#!/usr/bin/env python3

from typing import Generator
import random

players = [
    "alice",
    "bob",
    "charlie",
    "dylan",
]

actions = [
    "run",
    "eat",
    "sleep",
    "grab",
    "move",
    "climb",
    "swim",
    "release",
]


def gen_event() -> Generator[tuple[str, str], None, None]:
    while True:
        name = random.choice(players)
        action = random.choice(actions)
        event = (name, action)
        yield event


def consume_event(
        events: list[tuple[str, str]]
) -> Generator[tuple[str, str], None, None]:
    while events:
        event = random.choice(events)
        events.remove(event)
        yield event


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")

    generator = gen_event()

    for i in range(1000):
        event = next(generator)
        print(f"Event {i}: Player {event[0]} did action {event[1]}")

    events: list[tuple[str, str]] = []
    for i in range(10):
        event = next(generator)
        events.append(event)

    print(f"Built list of 10 events: {events}")

    for event in consume_event(events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events}")
