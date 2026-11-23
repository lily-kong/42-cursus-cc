#!/usr/bin/env python3

import typing
import abc


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self.data: list[str] = []
        self.rank = 0
        self.total_processed = 0
        self.name = "Data Processor"

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
        self.name = "Numeric Processor"

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
                self.total_processed += 1
        else:
            self.data.append(str(data))
            self.total_processed += 1


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()
        self.name = "Text Processor"

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
                self.total_processed += 1
        else:
            self.data.append(data)
            self.total_processed += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__()
        self.name = "Log Processor"

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
                self.total_processed += 1
        else:
            log = ": ".join(data.values())
            self.data.append(log)
            self.total_processed += 1


class DataStream:
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for data in stream:
            for proc in self.processors:
                if proc.validate(data):
                    proc.ingest(data)
                    break
            else:
                print(
                    "DataStream error - "
                    f"Can't process element in stream: {data}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if not self.processors:
            print("No processor found, no data")
            return

        for proc in self.processors:
            print(
                f"{proc.name}: "
                f"total {proc.total_processed} items processed, "
                f"remaining {len(proc.data)} on processor"
            )


if __name__ == "__main__":
    data_stream = DataStream()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    log1 = {
        "log_level": "WARNING",
        "log_message": "Telnet access! Use ssh instead"
    }
    log2 = {
        "log_level": "INFO",
        "log_message": "User wil is connected"
    }
    stream = [
        "Hello world",
        [3.14, -1, 2.71],
        [log1, log2],
        42,
        ["Hi", "five"],
    ]

    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    data_stream.print_processors_stats()
    print()
    print("Registering Numeric Processor")
    data_stream.register_processor(numeric)
    print()
    print(f"Send first batch of data on stream: {stream}")
    data_stream.process_stream(stream)
    data_stream.print_processors_stats()
    print()
    print("Registering other data processors")
    data_stream.register_processor(text)
    data_stream.register_processor(log)
    print("Send the same batch again")
    data_stream.process_stream(stream)
    data_stream.print_processors_stats()
    print()
    print(
        "Consume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    for _ in range(3):
        numeric.output()
    for _ in range(2):
        text.output()
    log.output()
    data_stream.print_processors_stats()
