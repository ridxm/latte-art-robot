from huggingface_hub import HfApi
from pathlib import Path

# Configuration
repo_id = "ridxm/latte-pour-demos"
tag = "v3.2"
dataset_path = "data"

dataset_dir = Path(dataset_path)

print("Verifying dataset structure...")

# Check required structure for LeRobot 0.4.0+
# Note: episodes in directory, tasks as single file
required = [
    "meta/info.json",
    "meta/episodes/chunk-000/file-000.parquet",  # Episodes in chunked format
    "meta/tasks.parquet",                         # Tasks as single file
    "meta/stats.json",
]

missing = []
for f in required:
    path = dataset_dir / f
    if path.exists():
        print(f"  OK {f}")
    else:
        print(f"  MISSING {f}")
        missing.append(f)

if missing:
    raise FileNotFoundError(f"Missing: {missing}")

print("\nDataset structure verified!")

# Initialize HuggingFace API
hub_api = HfApi()

# Create repo if it doesn't exist
print(f"\nCreating/checking dataset repo {repo_id}...")
hub_api.create_repo(repo_id=repo_id, repo_type="dataset", exist_ok=True)
print(f"Repo ready!")

# Upload the dataset
print(f"\nUploading dataset to {repo_id}...")
hub_api.upload_folder(
    repo_id=repo_id,
    folder_path=dataset_path,
    repo_type="dataset",
    commit_message=f"fix episodes format - chunked structure",
    commit_description="Fixed LeRobot format: meta/episodes/chunk-000/file-000.parquet",
)

print(f"Dataset uploaded successfully!")

print(f"\nCreating tag {tag}...")
try:
    hub_api.delete_tag(repo_id, tag=tag, repo_type="dataset")
    print(f"  Deleted existing tag {tag}")
except:
    pass

hub_api.create_tag(repo_id, tag=tag, repo_type="dataset")
print(f"Tag {tag} created successfully!")

print(f"\nUpload complete! Dataset available at:")
print(f"   https://huggingface.co/datasets/{repo_id}")
