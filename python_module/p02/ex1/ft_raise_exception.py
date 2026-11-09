#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)
    if temp > 40:
        raise Exception(f"{temp}°C is too hot for plants (max 40°C)")
    elif temp < 0:
        raise Exception(f"{temp}°C is too cold for plants (min 0°C)")
    return temp


def test_temperature() -> None:
    test_values = ["25", "abc", "100", "-50"]

    for value in test_values:
        print(f"Input data is '{value}'")
        try:
            temp = input_temperature(value)
            print(f"Temperature is now {temp}°C")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")
        except Exception as e:
            print(f"Caught input_temperature error: {e}")
        print()

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    print()
    test_temperature()
