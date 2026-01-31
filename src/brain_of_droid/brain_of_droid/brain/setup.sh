#!/bin/bash
echo "Setting up Python 3.11 virtual environment..."

# Check for python3.11
if ! command -v python3.11 &> /dev/null; then
    echo "Python 3.11 not found. Please install it and retry."
    exit 1
fi

# Create venv
python3.11 -m venv venv

# Activate and install
source venv/bin/activate
pip install -r requirements.txt

echo "Setup complete. Run 'source venv/bin/activate' to activate the environment."
