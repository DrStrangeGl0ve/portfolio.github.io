import requests
import time
import json
from tabulate import tabulate
from config import API_KEY

PLAYER_URL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-riot-id/"
MATCHES_URL = 'https://americas.api.riotgames.com/lol/match/v5/matches/'

# Initialize API call counter
api_call_count = 0

def make_request(url, headers):
    global api_call_count
    max_retries = 5
    retry_delay = 1  # Initial delay in seconds

    for attempt in range(max_retries):
        response = requests.get(url, headers=headers)
        api_call_count += 1

        if response.status_code == 200:
            # Extract rate limit headers
            app_rate_limit = response.headers.get("X-App-Rate-Limit", "")
            app_rate_limit_count = response.headers.get("X-App-Rate-Limit-Count", "")
            method_rate_limit = response.headers.get("X-Method-Rate-Limit", "")
            method_rate_limit_count = response.headers.get("X-Method-Rate-Limit-Count", "")

            # Calculate remaining API calls
            app_limits = [int(limit.split(":")[0]) for limit in app_rate_limit.split(",")]
            app_counts = [int(count.split(":")[0]) for count in app_rate_limit_count.split(",")]
            method_limits = [int(limit.split(":")[0]) for limit in method_rate_limit.split(",")]
            method_counts = [int(count.split(":")[0]) for count in method_rate_limit_count.split(",")]

            app_remaining = [limit - count for limit, count in zip(app_limits, app_counts)]
            method_remaining = [limit - count for limit, count in zip(method_limits, method_counts)]

            print(f"App Rate Limit Remaining: {app_remaining}")
            print(f"Method Rate Limit Remaining: {method_remaining}")

            return response.json()
        elif response.status_code == 429:  # Rate limit exceeded
            print("Rate limit exceeded. Retrying...")
            retry_after = int(response.headers.get("Retry-After", retry_delay))
            time.sleep(retry_after)
            retry_delay *= 2  # Exponential backoff
        elif response.status_code == 403:
            print("Error 403: Forbidden. Check your API key and permissions.")
            return None
        else:
            print(f"Error: {response.status_code}")
            print(response.json())
            return None

    print("Max retries exceeded.")
    return None

def get_player_data(gameName, tagName):
    url = f"{PLAYER_URL}{gameName}/{tagName}?api_key={API_KEY}"
    headers = {
        "X-Riot-Token": API_KEY
    }
    return make_request(url, headers)

def save_puuid_to_file(puuid, filename='puuid_data.txt'):
    with open(filename, 'w') as file:
        file.write(puuid)
    print(f"PUUID saved to {filename}")

def get_match_id(puuid, count):
    url = f"{MATCHES_URL}by-puuid/{puuid}/ids?start=0&count={count}"
    headers = {
        "X-Riot-Token": API_KEY
    }
    return make_request(url, headers)

def get_match_details(match_id):
    url = f"{MATCHES_URL}{match_id}?api_key={API_KEY}"
    headers = {
        "X-Riot-Token": API_KEY
    }
    return make_request(url, headers)

def get_match_timeline(match_id):
    url = f"{MATCHES_URL}{match_id}/timeline?api_key={API_KEY}"
    headers = {
        "X-Riot-Token": API_KEY
    }
    return make_request(url, headers)


def save_champion_kill_events(timeline, participant_id, participant_game_name):
    champion_kill_events = []
    for frame in timeline['info']['frames']:
        for event in frame['events']:
            if event['type'] == 'CHAMPION_KILL':
                if event['killerId'] == participant_id or event['victimId'] == participant_id:
                    champion_kill_events.append(event)
    
    data_to_save = []
    for event in champion_kill_events:
        game_time = event['timestamp'] // 1000  # Convert milliseconds to seconds
        killer_position = event['position']
        victim_position = event['position']
        killer_name = participant_game_name if event['killerId'] == participant_id else next(p['championName'] for p in participants if p['participantId'] == event['killerId'])
        victim_name = participant_game_name if event['victimId'] == participant_id else next(p['championName'] for p in participants if p['participantId'] == event['victimId'])
        data_to_save.append({
            "game_time": f"{game_time}s",
            "killer_name": killer_name,
            "victim_name": victim_name,
            "killer_position": {"x": killer_position.get('x', 'N/A'), "y": killer_position.get('y', 'N/A')},
            "victim_position": {"x": victim_position.get('x', 'N/A'), "y": victim_position.get('y', 'N/A')},
            "assisting_participant_ids": event.get('assistingParticipantIds', []),
            "player_name": participant_game_name
        })
    return data_to_save

gameName = input("Enter game Riot ID: ")
tagName = input("Enter tag line (no hashtag): ")


# Example usage
playerData = get_player_data(gameName, tagName)
if playerData:
    matchCount = int(input("Enter the number of matches you want to see: "))
    match_ids= get_match_id(playerData['puuid'], matchCount)
    all_events_data = []
    for match_id in match_ids:
            match_details = get_match_details(match_id)
            if match_details and match_details['info']['mapId'] == 11:
                # Find the participant ID that matches the puuid
                participant_id = None
                participant_game_name = None
                participant_champion_name = None
                participants = match_details['info']['participants']
                for participant in participants:
                    if participant['puuid'] == playerData['puuid']:
                        participant_id = participant['participantId']
                        participant_game_name = participant['summonerName']
                        participant_champion_name = participant['championName']
                        break
                print(f"Summoner: {participant_game_name}, Champion: {participant_champion_name}")

                match_timeline = get_match_timeline(match_id)
                if match_timeline:
                    # Extract and print CHAMPION_KILL events
                    events_data = save_champion_kill_events(match_timeline, participant_id, participant_game_name)
                    all_events_data.extend(events_data)
    with open('champion_kill_events.json', 'w') as f:
        json.dump(all_events_data, f, indent=4)
    print("Champion kill events saved to champion_kill_events.json")



# Print the number of API calls made
print(f"Total API calls made: {api_call_count}")