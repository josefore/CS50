import csv
import sys

"""
def cut(mylist):
    winner = list(mylist)
    if len(winner) == 1:
        return winner
    half = len(winner) / 2
    for i in range(int(half)):
        winner.pop(i)
    cut(winner)
    """
def cut(my_list):
    half = len(my_list) / 2
    for x in range(int(half)):
        my_list.pop(x)

def simulate(my_list):
    if len(my_list) == 0:
        return None
    if len(my_list) == 1:
        return my_list
    cut(my_list)
    simulate(my_list)

def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python openfile.py FILENAME")
    my_list = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in list(reader):
            row["rating"] = int(row["rating"])
            my_list.append(row)
    print(my_list)

    counts = {}
    for x in my_list:
        counts.update({x["team"]: 0})

    for i in range(10):
        if simulate(my_list) == None:
            continue

        winner = [i["team"] for i in simulate(my_list)]
        team_name = winner[0]
        score = counts.get(team_name)
        counts.update({team_name: (score + 1)})
    print(counts)


main()