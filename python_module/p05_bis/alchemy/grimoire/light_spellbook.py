#!/usr/bin/env python3

def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:

    from .light_validator import validate_ingredients

    record = validate_ingredients(ingredients)

    if "VALID" in record:
        return f"Spell recorded: {spell_name} ({record})"

    return f"Spell recorded: {spell_name} ({record})"
