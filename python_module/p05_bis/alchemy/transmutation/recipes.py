#!/usr/bin/env python3

import alchemy
from elements import create_fire
from ..potions import strength_potion


def lead_to_gold() -> str:
    return "Recipe transmuting Lead to Gold: " \
        f"brew '{alchemy.create_air()}' and '{strength_potion()}' " \
        f"mixed with '{create_fire()}'"
