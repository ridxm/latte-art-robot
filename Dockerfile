# Dockerfile for VESSL H100 Training
# LeRobot π0 fine-tuning for latte art robot

FROM nvidia/cuda:12.4.1-cudnn-devel-ubuntu22.04

# Prevent interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# System dependencies
RUN apt-get update && apt-get install -y \
    python3.11 \
    python3.11-venv \
    python3-pip \
    git \
    git-lfs \
    ffmpeg \
    libsm6 \
    libxext6 \
    libgl1-mesa-glx \
    && rm -rf /var/lib/apt/lists/*

# Set Python 3.11 as default
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3.11 1 \
    && update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.11 1

# Install uv for fast package management
RUN pip install uv

# Set working directory
WORKDIR /app

# Copy project files
COPY pyproject.toml uv.lock ./
COPY scripts/ ./scripts/
COPY configs/ ./configs/

# Install dependencies with uv
RUN uv pip install --system -e . \
    && uv pip install --system wandb huggingface_hub

# Environment variables for H100 optimization
ENV CUDA_VISIBLE_DEVICES=0
ENV PYTORCH_CUDA_ALLOC_CONF=expandable_segments:True
ENV TORCH_CUDNN_V8_API_ENABLED=1
ENV TOKENIZERS_PARALLELISM=false

# Cache directories
ENV HF_HOME=/root/.cache/huggingface
ENV WANDB_DIR=/app/wandb

# Default command
CMD ["python", "scripts/train.py"]
