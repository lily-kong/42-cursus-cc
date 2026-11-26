#!/usr/bin/env python3
from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from enum import Enum


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode="after")
    def validate_contact(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError(
                'Contact ID must start with "AC"'
            )
        if (
            self.contact_type == ContactType.PHYSICAL
            and not self.is_verified
        ):
            raise ValueError(
                "Physical contact reports must be verified"
            )
        if (
            self.contact_type == ContactType.TELEPATHIC
            and self.witness_count < 3
        ):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )
        if (
            self.signal_strength > 7.0
            and self.message_received is None
        ):
            raise ValueError(
                "Strong signals (> 7.0) should include received messages"
            )
        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")
    print("Valid contact report:")
    report = AlienContact(
        contact_id="AC_2024_001",
        timestamp=datetime(2026, 11, 25),
        location="Area 51, Nevada",
        contact_type=ContactType.RADIO,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli"
    )
    print(
        f"ID: {report.contact_id}\n"
        f"Type: {report.contact_type.value}\n"
        f"Location: {report.location}\n"
        f"Signal: {report.signal_strength}/10\n"
        f"Duration: {report.duration_minutes} minutes\n"
        f"Witnesses: {report.witness_count}\n"
        f"Message: '{report.message_received}'"
    )
    print()
    print("======================================")
    print("Expected validation error:")
    try:
        AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime(2026, 11, 25),
            location="Area 51, Nevada",
            contact_type=ContactType.TELEPATHIC,
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=1,
            message_received="Greetings from Zeta Reticuli"
        )
    except ValidationError as e:
        for error in e.errors():
            print(error["msg"].removeprefix("Value error, "))


if __name__ == "__main__":
    main()
