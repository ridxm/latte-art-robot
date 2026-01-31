from langchain_core.tools import tool


@tool
def move_head_yes(query: str) -> str:
    """This tool nods the robot’s head to signal “yes”."""
    print("✅ head nod (yes)")
    return f"[move_head_yes] Responded to: {query}"


@tool
def move_head_no(query: str) -> str:
    """This tool shakes the robot’s head to signal “no”."""
    print("❌ head shake (no)")
    return f"[move_head_no] Responded to: {query}"


@tool
def move_arms_while_speaking(query: str) -> str:
    """
    Always use this tool when the robot is speaking.
    This tool moves the robot’s arms to emphasize speech—
    hand gestures for a more expressive conversation.
    """
    print("🤖 moving arms while speaking")
    return f"[move_arms_while_speaking] Responded to: {query}"


@tool
def wave_with_right_arm(query: str) -> str:
    """This tool makes the robot wave its right arm. Use this to greet or acknowledge someone."""
    print("👋 waving with right arm")
    return f"[wave_with_right_arm] Responded to: {query}"


# List of tools for binding to the LLM
TOOLS = [
    move_head_yes,
    move_head_no,
    move_arms_while_speaking,
    wave_with_right_arm,
]

# Dict mapping tool names (as the LLM will call them) → tool fns
TOOLS_DICT = {tool_fn.name: tool_fn for tool_fn in TOOLS}
