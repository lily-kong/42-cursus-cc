#!/usr/bin/env python3

from .dark_spellbook import dark_spell_allowed_ingredients


def dark_validate_ingredients(ingredients: str) -> str:
    dark_list = dark_spell_allowed_ingredients()

    for ingredient in dark_list:
        if ingredient in ingredients.lower():
            return f"{ingredients} - VALID"

    return f"{ingredients} - INVALID"
