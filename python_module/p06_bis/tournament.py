#!/usr/bin/env python3
import typing
from ex3 import CreatureFactory, FlameFactory, TransformCreatureFactory
from ex4 import BattleError, BattleStrategy, NormalStrategy, AggressiveStrategy


def battle(
    opponents: typing.Sequence[tuple[CreatureFactory, BattleStrategy]]
) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    print()

    for i, (factory1, strategy1) in enumerate(opponents):
        for factory2, strategy2 in opponents[(i + 1):]:

            creature1 = factory1.create_base()
            creature2 = factory2.create_base()

            print("* Battle *")
            print(creature1.describe())
            print("vs.")
            print(creature2.describe())
            print("now fight!")
            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
            except BattleError as e:
                print(f"Battle error, aborting tournament: {e}")
                return


if __name__ == "__main__":
    flame_factory = FlameFactory()
    transform_factory = TransformCreatureFactory()
    normal_strat = NormalStrategy()
    aggressive_strat = AggressiveStrategy()
    list_basic = [
        (flame_factory, normal_strat),
        (transform_factory, aggressive_strat)
    ]
    list_error = [
        (transform_factory, aggressive_strat),
        (flame_factory, aggressive_strat)
    ]

    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Shiftling+Aggressive) ]")
    battle(list_basic)
    print()
    print("Tournament 1 (error)")
    print("[ (Shiftling+Aggressive), (Flameling+Aggressive) ]")
    battle(list_error)
