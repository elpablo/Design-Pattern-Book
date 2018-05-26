#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Chart(ABC):
    """
    Abstract class that defines the template methods
    """
    def __init__(self):
        pass

    def _vetting_data(self):
        print("remove non valid values -> ")

    def _features_extraction(self):
        print("extract chart data -> ")

    @abstractmethod
    def _read_data(self):
        pass

    @abstractmethod
    def _draw_data(self):
        pass

    def execute(self):
        self._read_data()
        self._vetting_data()
        self._features_extraction()
        self._draw_data()


class LineChart(Chart):
    def _read_data(self):
        print("read LineChart data -> ")

    def _draw_data(self):
        print("Draw data as line chart")


class PieChart(Chart):
    def _read_data(self):
        print("read PieChart data -> ")

    def _draw_data(self):
        print("Draw data as pie chart")


def main():
    charts = [LineChart(), PieChart()]

    for c in charts:
        c.execute()
        print("\n")


if __name__ == '__main__':
    main()


"""
Output:

read LineChart data -> 
remove non valid values -> 
extract chart data -> 
Draw data as line chart


read PieChart data -> 
remove non valid values -> 
extract chart data -> 
Draw data as pie chart

"""
