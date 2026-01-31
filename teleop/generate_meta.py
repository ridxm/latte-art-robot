from MetaRecorder import MetaRecorder

from DataCollectionConstants import DATA_FOLDER_PATH, IMAGE_HEIGHT, IMAGE_WIDTH

def main():
    image_size = (IMAGE_HEIGHT, IMAGE_WIDTH, 3)
    meta_recorder = MetaRecorder(data_folder_path=DATA_FOLDER_PATH, image_size=image_size)
    meta_recorder.generate_episodes_jsonl()
    meta_recorder.generate_info_json()
    meta_recorder.generate_tasks_jsonl()
    meta_recorder.generate_stats_json()

if __name__ == "__main__":
    main()