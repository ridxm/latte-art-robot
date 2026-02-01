from huggingface_hub import HfApi
import os
import json
from pathlib import Path
import pandas as pd

# Configuration
repo_id = "dwux/realman_pour1"
tag = "v3.0"
dataset_path = "data"

dataset_dir = Path(dataset_path)
required_files = [
    "meta/info.json",
]

print("Verifying dataset structure...")
missing_files = []
for file_path in required_files:
    if not (dataset_dir / file_path).exists():
        missing_files.append(file_path)
        print(f"  ❌ {file_path} - MISSING")
    else:
        print(f"  ✅ {file_path}")

if missing_files:
    raise FileNotFoundError(f"Missing required files: {missing_files}")

print("\n✅ Dataset structure verified!")

# Convert jsonl files to parquet if needed (LeRobot 0.4.0+ expects parquet)
meta_dir = dataset_dir / "meta"

def jsonl_to_parquet(jsonl_path, parquet_path):
    """Convert a jsonl file to parquet format."""
    records = []
    with open(jsonl_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line:
                records.append(json.loads(line))
    if records:
        df = pd.DataFrame(records)
        df.to_parquet(parquet_path, index=False)
        return True
    return False

print("\nConverting metadata to parquet format...")

# Convert tasks.jsonl to tasks.parquet
tasks_jsonl = meta_dir / "tasks.jsonl"
tasks_parquet = meta_dir / "tasks.parquet"
if tasks_jsonl.exists() and not tasks_parquet.exists():
    if jsonl_to_parquet(tasks_jsonl, tasks_parquet):
        print(f"  ✅ Converted tasks.jsonl → tasks.parquet")
elif tasks_parquet.exists():
    print(f"  ✅ tasks.parquet already exists")

# Convert episodes.jsonl to episodes.parquet
episodes_jsonl = meta_dir / "episodes.jsonl"
episodes_parquet = meta_dir / "episodes.parquet"
if episodes_jsonl.exists() and not episodes_parquet.exists():
    if jsonl_to_parquet(episodes_jsonl, episodes_parquet):
        print(f"  ✅ Converted episodes.jsonl → episodes.parquet")
elif episodes_parquet.exists():
    print(f"  ✅ episodes.parquet already exists")

print("✅ Metadata conversion complete!")

# Initialize HuggingFace API
hub_api = HfApi()

# Upload the dataset
print(f"\nUploading dataset to {repo_id}...")
hub_api.upload_folder(
    repo_id=repo_id,
    folder_path=dataset_path,
    repo_type="dataset",
    commit_message=f"upload pour dataset",
    commit_description=("Opendroid/realman pour dataset" ),
)

print(f"✅ Dataset uploaded successfully!")

print(f"\nCreating tag {tag}...")
try:
    hub_api.delete_tag(repo_id, tag=tag, repo_type="dataset")
    print(f"  Deleted existing tag {tag}")
except:
    pass

hub_api.create_tag(repo_id, tag=tag, repo_type="dataset")
print(f"✅ Tag {tag} created successfully!")

print(f"\n🎉 Upload complete! Dataset available at:")
print(f"   https://huggingface.co/datasets/{repo_id}")
