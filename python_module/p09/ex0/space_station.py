#!/usr/bin/env python3
from pydantic import BaseModel, Field, ValidationError
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


def main() -> None:
    print("Space Station Data Validation")
    print("========================================")
    print("Valid station created:")
    station = SpaceStation(
        station_id="ISS001",
        name="International Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        last_maintenance=datetime(2026, 11, 25)
    )
    status = 'Operational' if station.is_operational else 'Not Operational'
    print(
        f"ID: {station.station_id}\n"
        f"Name: {station.name}\n"
        f"Crew: {station.crew_size} people\n"
        f"Power: {station.power_level}%\n"
        f"Oxygen: {station.oxygen_level}%\n"
        f"Status: {status}"
    )
    print()
    print("========================================")
    print("Expected validation error:")
    try:
        SpaceStation(
            station_id="ISS002",
            name="International Invalid Station",
            crew_size=50,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime(2026, 11, 25)
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"])


if __name__ == "__main__":
    main()
