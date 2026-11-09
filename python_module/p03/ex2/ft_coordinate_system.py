#!/usr/bin/env python3

import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        user_input = input(
            "Enter new coordinates "
            "as floats in format 'x,y,z': "
        )

        coordinates = user_input.split(",")

        if len(coordinates) == 3:

            for coordinate in coordinates:
                try:
                    float(coordinate)
                except ValueError:
                    print(
                        f"Error on parameter '{coordinate}': "
                        f"could not convert string to float: '{coordinate}'"
                    )
                    break

            else:
                x = float(coordinates[0])
                y = float(coordinates[1])
                z = float(coordinates[2])

                user_pos = (x, y, z)
                break

        else:
            print("Invalid syntax")

    return user_pos


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    pos1 = get_player_pos()
    print(f"Got a first tuple: {pos1}")
    print(f"It includes: X={pos1[0]}, Y={pos1[1]}, Z={pos1[2]}")
    distance = math.sqrt(pos1[0] ** 2 + pos1[1] ** 2 + pos1[2] ** 2)
    print(f"Distance to center: {round(distance, 4)}")
    print()
    print("Get a second set of coordinates")
    pos2 = get_player_pos()
    distance = math.sqrt(
        (pos2[0] - pos1[0]) ** 2 +
        (pos2[1] - pos1[1]) ** 2 +
        (pos2[2] - pos1[2]) ** 2
    )
    print(f"Distance between the 2 sets of coordinates: {round(distance, 4)}")
