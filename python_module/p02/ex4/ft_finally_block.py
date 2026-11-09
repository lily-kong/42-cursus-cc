#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        Exception.__init__(self, message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        GardenError.__init__(self, message)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    valid_plants = ["Tomato", "Lettuce", "Carrots"]
    invalid_plants = ["Tomato", "lettuce", "carrots"]

    for plants in [valid_plants, invalid_plants]:
        if plants == valid_plants:
            print("Testing valid plants...")
        else:
            print("Testing invalid plants...")
        print("Opening watering system")
        try:
            for plant in plants:
                water_plant(plant)
        except PlantError as e:
            print(f"Caught PlantError: {e}")
            print(".. ending tests and returning to main")
            return
        finally:
            print("Closing watering system")
            print()


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    print()
    test_watering_system()
    print("Cleanup always happens, even with errors!")
