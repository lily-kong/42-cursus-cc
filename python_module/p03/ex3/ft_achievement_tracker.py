#!/usr/bin/env python3

import random

achievements = {
    "Crafting Genius",
    "Strategist",
    "World Savior",
    "Speed Runner",
    "Survivor",
    "Master Explorer",
    "Treasure Hunter",
    "Unstoppable",
    "First Steps",
    "Collector Supreme",
    "Untouchable",
    "Sharp Mind",
    "Boss Slayer",
}


def gen_player_achievements() -> set[str]:
    number = random.randint(3, 10)
    player_achievements = random.sample(list(achievements), number)
    return set(player_achievements)


if __name__ == "__main__":
    alice = gen_player_achievements()
    bob = gen_player_achievements()
    charlie = gen_player_achievements()
    dylan = gen_player_achievements()
    distinct = alice | bob | charlie | dylan
    common = alice & bob & charlie & dylan

    print("=== Achievement Tracker System ===")
    print()
    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    print()
    print(f"All distinct achievements: {distinct}")
    print()
    print(f"Common achievements: {common}")
    print()
    print(f"Only Alice has: {alice - (bob | charlie | dylan)}")
    print(f"Only Bob has: {bob - (alice | charlie | dylan)}")
    print(f"Only Charlie has: {charlie - (alice | bob | dylan)}")
    print(f"Only Dylan has: {dylan - (alice | bob | charlie)}")
    print()
    print(f"Alice is missing: {achievements - alice}")
    print(f"Bob is missing: {achievements - bob}")
    print(f"Charlie is missing: {achievements - charlie}")
    print(f"Dylan is missing: {achievements - dylan}")
