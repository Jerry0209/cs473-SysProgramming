import dataclasses
import functools
import itertools
from typing import *

# configuration parameters

COUNT = [16, 64, 256]
DATALEN = range(1, 33)  # from 1 to 32
PACKED = [False, True]


@dataclasses.dataclass(frozen=True)
class DataPoint:
    count: int
    datalen: int
    packed: bool

    @functools.cache
    def desc(self) -> str:
        return f"(count = {self.count}, datalen = {self.datalen}, packed = {self.packed})"

    @functools.cache
    def encoded_name(self) -> str:
        return f"datapoint_{self.count}_{self.datalen}_{self.packed}"

    @functools.cache
    def entry(self) -> str:
        return self.encoded_name() + "_main"

    @functools.cache
    def objname(self) -> str:
        return self.encoded_name() + ".o"

    @functools.cache
    def cflags(self) -> str:
        l = []
        l.append(f"-DPARAM_COUNT={self.count}")
        l.append(f"-DPARAM_DATALEN={self.datalen}")
        l.append(f"-DPARAM_PACKED" if self.packed else "")
        l.append(f"-DPARAM_DESC=\"\\\"{self.desc()}\\\"\"")
        l.append(f"-DPARAM_ENTRY={self.entry()}")
        l.append(f"-save-temps")
        return " ".join(l)

    @functools.cache
    def make_target(self) -> str:
        obj = f"$(BUILD)/src/datapoint/{self.objname()}"
        src = "src/datapoint/datapoint.c"
        cflags = self.cflags()
        return "\n".join([
            f"OBJS += {obj}",
            f"",
            f"{obj} : {src}",
            f"\tmkdir -p $(@D)",
            f"\t$(CC) $(_CFLAGS) $(CFLAGS) {cflags} -c $< -o $@",
            f"",
            f""
        ])


def make_entry_target(entries: List[str]):
    obj = f"$(BUILD)/src/datapoint/entry.o"
    src = "src/datapoint/entry.c"

    l = []
    for entry in entries:
        l.append(f"{entry}(); ")
    all_entries = "".join(l)

    cflags = f"-Wno-implicit-function-declaration -DALL_ENTRIES=\"{all_entries}\""
    return "\n".join([
        f"OBJS += {obj}",
        f"",
        f"{obj} : {src}",
        f"\tmkdir -p $(@D)",
        f"\t$(CC) $(_CFLAGS) $(CFLAGS) {cflags} -c $< -o $@",
        f"",
        f""
    ])


def generate() -> None:
    entries = []
    with open("datapoints.mk", "w") as f:
        for datapoint in [DataPoint(*x) for x in itertools.product(COUNT, DATALEN, PACKED)]:
            f.writelines(datapoint.make_target())
            entries.append(datapoint.entry())

        f.writelines([make_entry_target(entries)])


if __name__ == "__main__":
    print("generating: `datapoints.mk`")
    generate()
