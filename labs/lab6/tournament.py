# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in list(reader):
            row["rating"] = int(row["rating"])
            teams.append(row)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    # Create full team list
    for x in teams:
        counts.update({x["team"]: 0})

    # Update each score
    for i in range(N):
        team_name = simulate_tournament(teams)
        score = counts.get(team_name)
        counts.update({team_name: (score + 1)})

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winners = simulate_round(teams).copy()
    while len(winners) != 1:
        winners = simulate_round(winners)

    winner = [i["team"] for i in winners]
    mfchamp = winner[0]

    return mfchamp


if __name__ == "__main__":
    main()
