#!/usr/bin/env python3

import sys

inventory = {}

print("=== Inventory System Analysis ===")

for arg in sys.argv[1:]:
    user_input = arg.split(":")

    if len(user_input) == 2:
        item_name = user_input[0]

        try:
            item_quantity = int(user_input[1])
        except ValueError as e:
            print(f"Quantity error for '{item_name}': {e}")
            continue

        if item_name in inventory:
            print(f"Redundant item '{item_name}' - discarding")
        else:
            inventory[item_name] = item_quantity

    else:
        print(f"Error - invalid parameter '{arg}'")

total_quantity = sum(inventory.values())

print(f"Got inventory: {inventory}")
print(f"Item list: {list(inventory.keys())}")
print(f"Total quantity of the 5 items: {total_quantity}")

most_item = ""
most_quantity = 0
least_item = ""
least_quantity = 0

for item in inventory:
    if inventory[item] > most_quantity:
        most_quantity = inventory[item]
        most_item = item
    if least_quantity == 0 or inventory[item] < least_quantity:
        least_quantity = inventory[item]
        least_item = item
    try:
        print(
            f"Item {item} represents "
            f"{round((inventory[item] / total_quantity) * 100, 1)}%"
        )
    except ZeroDivisionError:
        pass

print(f"Item most abundant: {most_item} with quantity {most_quantity}")
print(f"Item least abundant: {least_item} with quantity {least_quantity}")
inventory.update({"magic_item": 1})
print(f"Updated inventory: {inventory}")
