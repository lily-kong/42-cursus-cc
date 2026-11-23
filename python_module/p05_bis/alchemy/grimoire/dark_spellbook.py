#!/usr/bin/env python3

from .dark_validator import dark_validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    record = dark_validate_ingredients(ingredients)

    if "VALID" in record:
        return f"Spell recorded: {spell_name} ({record})"

    return f"Spell recorded: {spell_name} ({record})"
