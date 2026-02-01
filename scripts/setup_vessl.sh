#!/bin/bash
# VESSL H100 Workspace Setup Script
# Run this after SSH'ing into the workspace

set -e

echo "=== LATTE ART ROBOT - VESSL SETUP ==="

# 1. Install system dependencies (ffmpeg for video decoding)
echo "Installing system dependencies..."
apt-get update && apt-get install -y ffmpeg

# 2. Install uv if not present
if ! command -v uv &> /dev/null; then
    echo "Installing uv..."
    curl -LsSf https://astral.sh/uv/install.sh | sh
    export PATH="$HOME/.local/bin:$PATH"
fi

# 2. Clone repo if not in it
if [ ! -f "pyproject.toml" ]; then
    echo "Cloning repo..."
    git clone https://github.com/ridxm/latte-art-robot
    cd latte-art-robot
fi

# 3. Create venv and install
echo "Creating venv and installing deps..."
uv venv --python 3.11
source .venv/bin/activate
uv pip install -e .

# 4. Verify GPU
echo ""
echo "=== GPU CHECK ==="
python -c "import torch; print(f'GPU: {torch.cuda.get_device_name(0)}'); print(f'CUDA: {torch.version.cuda}')"

echo ""
echo "=== SETUP COMPLETE ==="
echo ""
echo "Next steps:"
echo "  1. wandb login"
echo "  2. huggingface-cli login"
echo "  3. python scripts/train.py"
