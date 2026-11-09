#!/usr/bin/env python3

import random

names = [
    "Alice",
    "bob",
    "Charlie",
    "dylan",
    "Emma",
    "Gregory",
    "john",
    "kevin",
    "Liam",
]

upper_names = [name.capitalize() for name in names]
capitalized_names = [name for name in names if name[0].isupper()]
score_dict = {name: random.randint(0, 1000) for name in names}
scores = [score_dict[name] for name in score_dict]
score_average = round(sum(scores) / len(score_dict), 2)
high_scores = {
    name: score_dict[name]
    for name in score_dict
    if score_dict[name] > score_average
}


if __name__ == "__main__":
    print("=== Game Data Alchemist ===")
    print()
    print(f"Initial list of players: {names}")
    print(f"New list with all names capitalized: {upper_names}")
    print(f"New list of capitalized names only: {capitalized_names}")
    print()
    print(f"Score dict: {score_dict}")
    print(f"Score average is {score_average}")
    print(f"High scores: {high_scores}")
