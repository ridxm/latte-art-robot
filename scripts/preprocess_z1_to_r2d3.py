#!/usr/bin/env python3
"""Convert Unitree Z1 dual-arm datasets to the 12-DoF Realman layout.

This script remaps the 14-element joint vectors (7 DoF per Z1 arm) to the
6-DoF Realman configuration used by the OpenDroid R2D3 robot. It drops the Z1
forearm roll joint on each arm, renames the remaining joints, and writes a new
LeRobot-compatible dataset directory that can be consumed by the existing
training pipeline.

Example:
    python scripts/preprocess_z1_to_r2d3.py \
        --input-dir /data/Z1_Dual_Dex1_PourCoffee_Dataset \
        --output-dir data/coffee_r2d3

The script copies the dataset directory structure, rewrites the parquet files
under ``data/chunk-*/`` and updates ``meta/info.json`` with the Realman joint
names.
"""

from __future__ import annotations

import argparse
import json
import shutil
from pathlib import Path
from typing import Iterable, List

import numpy as np
import pyarrow as pa
import pyarrow.parquet as pq


# Joint order documented in the Unitree Z1 dataset README (7 DoF per arm).
DEFAULT_Z1_JOINTS = [
    "l_shoulder_roll",
    "l_shoulder_pitch",
    "l_shoulder_yaw",
    "l_elbow",
    "l_wrist_pitch",
    "l_wrist_yaw",
    "l_wrist_roll",
    "r_shoulder_roll",
    "r_shoulder_pitch",
    "r_shoulder_yaw",
    "r_elbow",
    "r_wrist_pitch",
    "r_wrist_yaw",
    "r_wrist_roll",
]

# Target layout for the dual Realman RM65 arms (6 DoF each).
REALMAN_JOINTS = [
    "l_joint1",
    "l_joint2",
    "l_joint3",
    "l_joint4",
    "l_joint5",
    "l_joint6",
    "r_joint1",
    "r_joint2",
    "r_joint3",
    "r_joint4",
    "r_joint5",
    "r_joint6",
]


def build_index_map(z1_joints: Iterable[str]) -> List[int]:
    """Return indices that map Z1 joints to the 12-DoF Realman layout."""

    z1 = list(z1_joints)
    try:
        left_idxs = [z1.index(name) for name in DEFAULT_Z1_JOINTS[:6]]
        right_idxs = [z1.index(name) for name in DEFAULT_Z1_JOINTS[7:13]]
    except ValueError as exc:  # pragma: no cover - defensive in case of mismatch
        raise ValueError(
            "Z1 joint names missing from dataset metadata. "
            "Double-check DEFAULT_Z1_JOINTS or pass --z1-joints explicitly."
        ) from exc

    return left_idxs + right_idxs


def remap_vector(vec: np.ndarray, indices: List[int]) -> np.ndarray:
    """Slice a 14-element vector down to Realman 12-element layout."""

    arr = np.asarray(vec)
    if arr.shape[-1] == len(indices):
        return arr  # already converted (idempotent)
    if arr.shape[-1] != len(indices) + 2:  # expect 14 values -> 12
        raise ValueError(f"Expected vector with 14 values, got shape {arr.shape}")
    return arr[..., indices]


def process_parquet_file(parquet_path: Path, columns: List[str], indices: List[int]) -> None:
    """Rewrite selected list columns in-place with the remapped values."""

    table = pq.read_table(parquet_path)
    data = table.to_pydict()

    for column in columns:
        if column not in data:
            continue  # column might not exist in every dataset chunk
        data[column] = [remap_vector(vec, indices).tolist() for vec in data[column]]

    pq.write_table(pa.Table.from_pydict(data), parquet_path)


def update_meta_info(meta_dir: Path) -> None:
    """Ensure the metadata advertises the Realman joint layout."""

    info_path = meta_dir / "info.json"
    if not info_path.exists():
        return

    info = json.loads(info_path.read_text())
    info["robot_joint_names"] = REALMAN_JOINTS
    info.setdefault("actuator", {})
    info["actuator"]["joint_names"] = REALMAN_JOINTS
    info_path.write_text(json.dumps(info, indent=2))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Remap Z1 dataset to Realman joints")
    parser.add_argument("--input-dir", required=True, help="Path to downloaded Z1 dataset")
    parser.add_argument(
        "--output-dir",
        required=True,
        help="Where to write the remapped dataset (must not exist unless --overwrite)",
    )
    parser.add_argument(
        "--overwrite",
        action="store_true",
        help="Allow writing into an existing output directory",
    )
    parser.add_argument(
        "--vector-columns",
        nargs="+",
        default=[
            "observation.state.joint_position",
            "observation.state.joint_velocity",
            "action.joint_position",
        ],
        help="LeRobot column names that store 14-element joint vectors",
    )
    parser.add_argument(
        "--z1-joints",
        nargs="+",
        default=DEFAULT_Z1_JOINTS,
        help="Override the joint name ordering from the Z1 dataset",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    input_dir = Path(args.input_dir).expanduser().resolve()
    output_dir = Path(args.output_dir).expanduser().resolve()

    if not input_dir.exists():
        raise FileNotFoundError(f"Input dataset not found: {input_dir}")

    if output_dir.exists():
        if not args.overwrite:
            raise FileExistsError(
                f"Output directory {output_dir} already exists (pass --overwrite to reuse)"
            )
    else:
        output_dir.parent.mkdir(parents=True, exist_ok=True)

    shutil.copytree(input_dir, output_dir, dirs_exist_ok=True)

    indices = build_index_map(args.z1_joints)

    data_root = output_dir / "data"
    for parquet_path in data_root.rglob("*.parquet"):
        process_parquet_file(parquet_path, args.vector_columns, indices)

    update_meta_info(output_dir / "meta")
    print(f"✅ Remapped dataset written to {output_dir}")


if __name__ == "__main__":
    main()
