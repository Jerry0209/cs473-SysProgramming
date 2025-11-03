import matplotlib
import matplotlib.pyplot as plt
import re
import pathlib
import dataclasses
from typing import *

REGEX = r"^.*?(\d+).*?(\d+).*?(True|False).*?(\d+).*?(\d+)$"
COUNT = 256


@dataclasses.dataclass(frozen=True)
class Row:
    count: int
    datalen: int
    packed: bool
    sizeof: int
    misses: int


def load_data(fpath: pathlib.Path) -> List[Row]:
    l: List[Row] = []

    with open(fpath) as f:
        matches = re.finditer(REGEX, f.read(), re.MULTILINE)
        for match in matches:
            groups = match.groups()
            l.append(Row(
                count=int(groups[0]),
                datalen=int(groups[1]),
                packed=groups[2] == "True",
                sizeof=int(groups[3]),
                misses=int(groups[4])
            ))

    return l


def set_font():
    font = {'size': 16}
    matplotlib.rc('font', **font)


def fig_axes(title, ylabel, xlabel):
    fig = plt.figure(figsize=[8, 6])
    axes = fig.add_axes([0.12, 0.12, 0.80, 0.80])
    axes.set_title(title, fontdict={"weight": "bold"})
    axes.set_xlabel(xlabel, fontdict={"weight": "bold"})
    axes.set_ylabel(ylabel, fontdict={"weight": "bold"})
    return (fig, axes)


def plot1(data: List[Row]):
    # sizeof vs datalen
    print("plot1")
    fig, axes = fig_axes(
        "Struct Size", "Struct Size (bytes)", "Data Length (bytes)")

    x = sorted(set(map(lambda x: x.datalen, data)))
    y_packed = list(map(lambda x: x.sizeof, filter(
        lambda x: x.packed and x.count == COUNT, data)))
    y_notpacked = list(map(lambda x: x.sizeof, filter(
        lambda x: not x.packed and x.count == COUNT, data)))

    axes.grid()

    axes.set_ylim([2, 38])
    axes.set_xticks([0, 4, 8, 12, 16, 20, 24, 28, 32])
    axes.set_yticks([4, 8, 12, 16, 20, 24, 28, 32, 36])

    axes.plot(x, y_packed, label="Packed", marker="o")
    axes.plot(x, y_notpacked, label="Not Packed", marker="o")
    axes.legend()

    fig.savefig("plot1.pdf")


def plot2(data: List[Row]):
    # sizeof vs datalen
    print("plot2")
    fig, axes = fig_axes(
        "Data Cache Misses", "Number of Misses", "Data Length (bytes)")

    x = sorted(set(map(lambda x: x.datalen, data)))
    y_packed = list(map(lambda x: x.misses, filter(
        lambda x: x.packed and x.count == COUNT, data)))
    y_notpacked = list(map(lambda x: x.misses, filter(
        lambda x: not x.packed and x.count == COUNT, data)))

    axes.grid()

    axes.set_xticks([0, 4, 8, 12, 16, 20, 24, 28, 32])

    axes.plot(x, y_packed, label="Packed", marker="o")
    axes.plot(x, y_notpacked, label="Not Packed", marker="o")
    axes.legend()

    fig.savefig("plot2.pdf")


if __name__ == "__main__":
    set_font()
    data = load_data("data.txt")
    plot1(data)
    plot2(data)
