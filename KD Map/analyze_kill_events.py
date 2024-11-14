import json
import tabulate
import matplotlib.pyplot as plt
from PIL import Image

def load_champion_kill_events(filename='champion_kill_events.json'):
    with open(filename, 'r') as f:
        data = json.load(f)
    return data

def scale_coordinates(x, y, original_max=32000, new_max=240):
    scale_factor = new_max / original_max
    return x * scale_factor, y * scale_factor

def convert_timestamp_to_minutes_seconds(timestamp):
    timestamp = int(timestamp.rstrip('s'))  # Remove 's' and ensure timestamp is an integer
    minutes = timestamp // 60
    seconds = timestamp % 60
    return f"{minutes}:{seconds:02d}"

def analyze_kill_events(data):
    # Lists to store scaled coordinates and timestamps
    player_killer_positions = []
    player_victim_positions = []
    player_killer_timestamps = []
    player_victim_timestamps = []

    # Extract player name from the first event
    player_name = data[0]['player_name'] if data else None

    table_data = []
    # Example analysis: Print the data with scaled coordinates
    for event in data:
        scaled_killer_x, scaled_killer_y = scale_coordinates(event['killer_position']['x'], event['killer_position']['y'])
        scaled_victim_x, scaled_victim_y = scale_coordinates(event['victim_position']['x'], event['victim_position']['y'])
        timestamp = convert_timestamp_to_minutes_seconds(event['game_time'])
        if event['killer_name'] == player_name:  # Use the player's name from the JSON data
            player_killer_positions.append((scaled_killer_x, scaled_killer_y))
            player_killer_timestamps.append(timestamp)
        if event['victim_name'] == player_name:  # Use the player's name from the JSON data
            player_victim_positions.append((scaled_victim_x, scaled_victim_y))
            player_victim_timestamps.append(timestamp)
        table_data.append([timestamp, event['killer_name'], event['victim_name'], f"({scaled_killer_x}, {scaled_killer_y})", f"({scaled_victim_x}, {scaled_victim_y})", event['assisting_participant_ids']])

    headers = ["Game Time", "Killer Name", "Victim Name", "Killer Position", "Victim Position", "Assisting Participant IDs"]
    print(tabulate.tabulate(table_data, headers=headers, tablefmt='fancy_grid'))
    # Plot the coordinates on a grid with x and y ranges from -120 to 120
    fig, ax = plt.figure(figsize=(8, 8)), plt.gca()
    fig.patch.set_alpha(0)
    ax.patch.set_alpha(0)
    if player_killer_positions:
        plt.scatter(*zip(*player_killer_positions), c='blue', label='Kill')
        for (x, y), timestamp in zip(player_killer_positions, player_killer_timestamps):
            plt.annotate(timestamp, (x, y), textcoords="offset points", xytext=(0,5), ha='center', fontsize=8, color='blue')
    if player_victim_positions:
        plt.scatter(*zip(*player_victim_positions), c='red', label='Death')
        for (x, y), timestamp in zip(player_victim_positions, player_victim_timestamps):
            plt.annotate(timestamp, (x, y), textcoords="offset points", xytext=(0,5), ha='center', fontsize=8, color='red')
    plt.xlim(0, 100)
    plt.ylim(0, 100)

    # Remove inner grid lines, axis numbers, and labels
    plt.grid(False)
    plt.xticks([])
    plt.yticks([])
    plt.xlabel('')
    plt.ylabel('')

    # Save the plot as a transparent PNG image
    transparent_png_path = 'champion_kill_positions.png'
    plt.savefig(transparent_png_path, bbox_inches='tight', pad_inches=0, dpi=200, transparent=True)
    print("Plot saved as champion_kill_positions.png")

    # Show the plot
    plt.show()
    print("Plot displayed")

    # Save the plot as a PNG image
    summoners_rift_image_path = 'summoners_rift.png'  # Path to the Summoner's Rift image
    output_image_path = 'overlayed_image.png'

    # Open the Summoner's Rift image and the transparent PNG
    base_image = Image.open(summoners_rift_image_path).convert("RGBA")
    overlay_image = Image.open(transparent_png_path).convert("RGBA")
    overlay_image = overlay_image.resize(base_image.size, Image.LANCZOS)

    # Overlay the images
    combined_image = Image.alpha_composite(base_image, overlay_image)

    # Save the combined image
    combined_image.save(output_image_path)
    print(f"Overlayed image saved as {output_image_path}")


# Load and analyze the data
champion_kill_events = load_champion_kill_events()
analyze_kill_events(champion_kill_events)