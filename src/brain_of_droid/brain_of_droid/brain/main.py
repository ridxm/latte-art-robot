import json
import speech_recognition as sr
import pyttsx3
from typing import TypedDict, Sequence, Annotated
from operator import add as add_messages
from langchain_core.messages import SystemMessage, HumanMessage, ToolMessage
from langgraph.graph import StateGraph, END
from langchain_openai import ChatOpenAI
from src.tools import TOOLS, TOOLS_DICT
from dotenv import load_dotenv


load_dotenv()

# === Agent State Definition ===
class AgentState(TypedDict):
    """TypedDict for storing the conversation history."""

    messages: Annotated[
        Sequence[SystemMessage | HumanMessage | ToolMessage], add_messages
    ]


# === Agent Graph Definition ===


def create_graph(persona_path: str) -> StateGraph:
    """
    Create and compile the agent's state graph based on a persona file.

    The graph consists of two nodes:
      - llm: invokes the LLM with system prompt and new user messages.
      - use_tool: executes any required tools based on LLM tool_calls.

    The graph automatically aggregates messages using the add_messages operator.

    Args:
        persona_path: Path to a text file containing the persona system prompt.

    Returns:
        A compiled StateGraph ready for invocation.
    """
    # Load persona prompt
    with open(persona_path, "r") as f:
        persona = f.read().strip()
    system_prompt = persona

    # Initialize LLM with bound tools
    llm = ChatOpenAI(model="gpt-4o", temperature=0).bind_tools(TOOLS)

    def call_llm(state: AgentState) -> AgentState:
        """
        LLM node: prepend system prompt to history, invoke LLM, return only its response.

        Args:
            state: Current agent state with message history.

        Returns:
            A new partial state containing only the latest LLM response.
        """
        prev = list(state.get("messages", []))
        messages = [SystemMessage(content=system_prompt)] + prev
        response = llm.invoke(messages)
        return {"messages": [response]}

    def should_continue(state: AgentState) -> bool:
        """
        Determine if the last LLM output contains tool calls.

        Args:
            state: Current agent state with message history.

        Returns:
            True if the last message has pending tool_calls, False otherwise.
        """
        last = state["messages"][-1]
        return hasattr(last, "tool_calls") and bool(last.tool_calls)

    def use_tool(state: AgentState) -> AgentState:
        """
        Tool execution node: for each tool call in the last message, invoke the corresponding tool.

        Args:
            state: Current agent state with message history.

        Returns:
            A new partial state containing only the tool outputs.
        """
        # tool_calls may be dicts if returned by langgraph
        last = state["messages"][-1]
        tool_calls = getattr(last, "tool_calls", []) or []
        results: list[ToolMessage] = []
        for call in tool_calls:
            # handle both object and dict representations
            if isinstance(call, dict):
                name = call.get("name")
                args = call.get("args", {})
                call_id = call.get("id")
            else:
                name = getattr(call, "name", None)
                args = call.args
                call_id = getattr(call, "id", None)
            # parse args if JSON string
            if isinstance(args, str):
                try:
                    args = json.loads(args)
                except Exception:
                    args = {"query": args}
            query = args.get("query", "")
            if name in TOOLS_DICT:
                out = TOOLS_DICT[name].invoke(query)
            else:
                out = f"Tool '{name}' not recognized."
            results.append(ToolMessage(tool_call_id=call_id, name=name, content=out))
        return {"messages": results}
    
    # Build and compile the state graph
    graph = StateGraph(AgentState)
    graph.add_node("llm", call_llm)
    graph.add_node("use_tool", use_tool)
    graph.add_conditional_edges("llm", should_continue, {True: "use_tool", False: END})
    graph.add_edge("use_tool", "llm")
    graph.set_entry_point("llm")
    return graph.compile()


# === Speech I/O ===
engine = pyttsx3.init()
recognizer = sr.Recognizer()


def list_voices() -> Sequence[object]:
    """
    List available TTS voices installed in the system.

    Prints each voice index, name, and supported languages.

    Returns:
        A sequence of voice objects.
    """
    voices = engine.getProperty("voices")
    for idx, v in enumerate(voices):
        print(f"[{idx}] {v.name} {v.languages}")
    return voices


def set_voice(index: int) -> None:
    """
    Select a TTS voice by index.

    If the index is invalid, retains the default voice.

    Args:
        index: Index of the desired voice in the list from list_voices().
    """
    voices = engine.getProperty("voices")
    if 0 <= index < len(voices):
        engine.setProperty("voice", voices[index].id)
    else:
        print("Invalid voice index, using default.")


def speak(text: str) -> None:
    """
    Speak the given text using the TTS engine.

    Args:
        text: The string to be spoken aloud.
    """
    engine.say(text)
    engine.runAndWait()


def listen() -> str:
    """
    Capture audio from the microphone and transcribe to text using Google Speech Recognition.

    Falls back to keyboard input if PyAudio is not available.

    Returns:
        The recognized text, or an empty string on failure.
    """
    try:
        with sr.Microphone() as mic:
            print("🎤 Listening...")
            recognizer.adjust_for_ambient_noise(mic)
            audio = recognizer.listen(mic)
        try:
            print("🧠 Recognizing...")
            return recognizer.recognize_google(audio)
        except sr.UnknownValueError:
            return ""
        except sr.RequestError as e:
            print(f"Speech API error: {e}")
            return ""
    except (AttributeError, OSError) as e:
        # PyAudio not installed or no microphone found: fallback to text input
        print("Microphone not available or PyAudio missing, please type your input:")
        return input("> ")


# === Main Loop ===
def run_voice_agent(persona_path: str) -> None:
    """
    Run the interactive voice-based agent loop.

    1. Builds the agent graph from persona.
    2. Prompts user to select a TTS voice.
    3. Listens for user speech, processes via the LLM+tools graph, and speaks responses.
    4. Exits when user says "exit" or "quit".

    Args:
        persona_path: Path to the persona text file.
    """
    graph = create_graph(persona_path)
    state: AgentState = {"messages": []}

    # Voice selection
    print("Available Voices:")
    list_voices()
    idx = int(input("Select voice index: "))
    set_voice(idx)

    print("Say 'exit' or 'quit' to stop.")
    while True:
        user_speech = listen()
        if not user_speech:
            continue
        print(f"You: {user_speech}")
        if user_speech.lower() in ("exit", "quit"):
            speak("Goodbye!")
            break

        messages = [HumanMessage(content=user_speech)]
        # Send to agent
        state = graph.invoke({"messages": messages})  # type: ignore

        # Extract and speak the last response
        last = state["messages"][-1]
        text = getattr(last, "content", "")
        print(f"Agent: {text}")
        speak(text)


if __name__ == "__main__":
    """
    Entry point: expects an optional persona file path argument.
    """
    import sys

    persona_file = (
        sys.argv[1] if len(sys.argv) > 1 else "persona.txt"
    )
    run_voice_agent(persona_file)
