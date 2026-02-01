FROM nvcr.io/nvidia/pytorch:24.01-py3

# Install system dependencies
RUN apt-get update && apt-get install -y \
    git \
    ffmpeg \
    libsm6 \
    libxext6 \
    && rm -rf /var/lib/apt/lists/*

# Install LeRobot with pi0 dependencies
RUN pip install --upgrade pip
RUN pip install "lerobot[pi0]>=0.4.0"
RUN pip install wandb huggingface_hub

# Set up working directory
WORKDIR /app

# Copy training script
COPY scripts/train.py /app/train.py

# Default command
CMD ["python", "train.py"]
