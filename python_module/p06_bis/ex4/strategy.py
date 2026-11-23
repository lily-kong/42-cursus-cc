import abc
import typing
from .error import BattleError
from ex3.creature import Creature
from ex3.transform import TransformCapability


class BattleStrategy(abc.ABC):

    @abc.abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abc.abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise BattleError(
                f"Invalid Creature '{creature.name}' for this normal strategy"
            )

        print(creature.attack())

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, Creature)


class AggressiveStrategy(BattleStrategy):

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise BattleError(
                f"Invalid Creature '{creature.name}' "
                "for this aggressive strategy"
            )

        transformed_creature = typing.cast(TransformCapability, creature)

        print(transformed_creature.transform())
        print(creature.attack())
        print(transformed_creature.revert())

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)
