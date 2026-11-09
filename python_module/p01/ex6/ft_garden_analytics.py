#!/usr/bin/env python3

class Plant:

    class Statistics:
        def __init__(self, is_tree: bool = False) -> None:
            self.__grow_calls = 0
            self.__age_calls = 0
            self.__show_calls = 0
            self.__shade_calls = 0 if is_tree else None

        def record_grow(self) -> None:
            self.__grow_calls += 1

        def record_age(self) -> None:
            self.__age_calls += 1

        def record_show(self) -> None:
            self.__show_calls += 1

        def record_shade(self) -> None:
            if self.__shade_calls is not None:
                self.__shade_calls += 1

        def show_statistics(self) -> None:
            print(
                f"Stats: {self.__grow_calls} grow, "
                f"{self.__age_calls} age, {self.__show_calls} show"
            )
            if self.__shade_calls is not None:
                print(f"{self.__shade_calls} shade")

    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
    ) -> None:
        self.name = name
        self.height = height
        self.age_days = age_days
        self.stats = self.Statistics()

    @staticmethod
    def is_more_than_year(age_days: int) -> bool:
        return age_days > 365

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0, 0)

    def grow(self, growth_height: float) -> None:
        self.height = round(self.height + growth_height, 1)
        self.stats.record_grow()

    def age(self, growth_days: int) -> None:
        self.age_days += growth_days
        self.stats.record_age()

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age_days} days old")
        self.stats.record_show()


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        color: str
    ) -> None:
        super().__init__(name, height, age_days)
        self.color = color
        self.is_blooming = False

    def bloom(self) -> None:
        self.is_blooming = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self.is_blooming:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} has not bloomed yet")


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        color: str,
        seeds: int
    ) -> None:
        super().__init__(name, height, age_days, color)
        self.seeds = seeds

    def show(self) -> None:
        super().show()
        if self.is_blooming:
            print(f"Seeds: {self.seeds}")
        else:
            print("Seeds: 0")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, age_days)
        self.trunk_diameter = trunk_diameter
        self.stats = self.Statistics(is_tree=True)

    def produce_shade(self) -> None:
        print(
            f"Tree {self.name} now produces a shade of "
            f"{self.height:.1f}cm long and {self.trunk_diameter:.1f}cm wide."
        )
        self.stats.record_shade()

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter:.1f}cm")


def show_plant_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.name}]")
    plant.stats.show_statistics()


if __name__ == "__main__":
    rose = Flower("Rose", 15, 10, "red")
    sunflower = Seed("Sunflower", 80, 45, "yellow", 42)
    oak = Tree("Oak", 200, 365, 5)
    anonymous = Plant.anonymous()

    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_more_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_more_than_year(400)}")
    print()
    print("=== Flower")
    rose.show()
    show_plant_statistics(rose)
    print("[asking the rose to grow and bloom]")
    rose.grow(8)
    rose.bloom()
    rose.show()
    show_plant_statistics(rose)
    print()
    print("=== Tree")
    oak.show()
    show_plant_statistics(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    show_plant_statistics(oak)
    print()
    print("=== Seed")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow(30)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    show_plant_statistics(sunflower)
    print()
    print("=== Anonymous")
    anonymous.show()
    show_plant_statistics(anonymous)
