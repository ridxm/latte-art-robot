from huggingface_hub import HfApi
import os
from pathlib import Path
from lerobot.datasets.lerobot_dataset import LeRobotDataset

# Configuration
repo_id = "dwux/test_data_realman"
tag = "v3.0"
dataset_path = "data"

dataset_dir = Path(dataset_path)
required_files = [
    "meta/info.json",
    "meta/stats.json",
    "meta/episodes.jsonl",
    "meta/tasks.jsonl",
    "data/chunk_000/episode_000000.parquet",
the]

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

# Load and finalize dataset (required for proper parquet writer closure)
print("\nFinalizing dataset...")
dataset = LeRobotDataset(str(dataset_dir.resolve()))
dataset.finalize()
print("✅ Dataset finalized!")

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
