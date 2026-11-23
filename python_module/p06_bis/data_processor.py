#!/usr/bin/env python3

import typing
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self.data: list[str] = []
        self.rank = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.data:
            raise IndexError("No data available")

        item = self.data.pop(0)
        result = (self.rank, item)
        self.rank += 1

        return result


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: typing.Any) -> bool:
        if type(data) in (int, float):
            return True

        if isinstance(data, list):
            for item in data:
                if type(item) not in (int, float):
                    return False
            return True

        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for item in data:
                self.data.append(str(item))
        else:
            self.data.append(str(data))


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: typing.Any) -> bool:
        if type(data) is str:
            return True

        if isinstance(data, list):
            for item in data:
                if type(item) is not str:
                    return False
            return True

        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for item in data:
                self.data.append(item)
        else:
            self.data.append(data)


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()

    def validate(self, data: typing.Any) -> bool:
        if type(data) is dict:
            for key, value in data.items():
                if type(key) is not str or type(value) is not str:
                    return False
            return True

        if isinstance(data, list):
            for item in data:
                if type(item) is not dict:
                    return False
                for key, value in item.items():
                    if type(key) is not str or type(value) is not str:
                        return False
            return True

        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")

        if isinstance(data, list):
            for item in data:
                log = ": ".join(item.values())
                self.data.append(log)
        else:
            log = ": ".join(data.values())
            self.data.append(log)


if __name__ == "__main__":
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()

    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Processor...")
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate input 'Hello': {numeric.validate('Hello')}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric.ingest('foo')
    except ValueError as e:
        print(f"Got exception: {e}")
    print("Processing data: [1, 2, 3, 4, 5]")
    numeric.ingest([1, 2, 3, 4, 5])
    print("Extracting 3 values...")
    for _ in range(3):
        rank, value = numeric.output()
        print(f"Numeric value {rank}: {value}")

    print()
    print("Testing Text Processor...")
    print(f"Trying to validate input '42': {text.validate(42)}")
    print("Processing data: ['Hello', 'Nexus', 'World']")
    text.ingest(["Hello", "Nexus", "World"])
    print("Extracting 1 value...")
    rank, value = text.output()
    print(f"Text value {rank}: {value}")

    print()
    print("Testing Log Processor...")
    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")
    log1 = {"log_level": "NOTICE", "log_message": "Connection to server"}
    log2 = {"log_level": "ERROR", "log_message": "Unauthorized access!!"}
    print(f"Processing data: {[log1, log2]}")
    log.ingest([log1, log2])
    print("Extracting 2 values...")
    for _ in range(2):
        rank, value = log.output()
        print(f"Log entry {rank}: {value}")
