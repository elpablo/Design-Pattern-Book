#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Chart(ABC):
    """
    Abstract class that defines the template methods
    """
    def __init__(self):
        pass

    def _vetting_data(self):
        """
        Demo method used to demonstrate the Template Method Design Pattern
        :return: None
        """
        print("remove non valid values -> ")

    def _features_extraction(self):
        """
        Demo method used to demonstrate the Template Method Design Pattern
        :return: None
        """
        print("extract chart data -> ")

    @abstractmethod
    def _read_data(self):
        """
        Template method that will be customized by the child classes
        :return: None
        """
        pass

    @abstractmethod
    def _draw_data(self):
        """
        Template method that will be customized by the child classes
        :return: None
        """
        pass

    def execute(self):
        """
        Demo method that will use the template methods together with the regular ones
        :return: None
        """
        self._read_data()
        self._vetting_data()
        self._features_extraction()
        self._draw_data()


class LineChart(Chart):
    """
    Child class that will implement a version of Template Methods
    """
    def _read_data(self):
        print("read LineChart data -> ")

    def _draw_data(self):
        print("Draw data as line chart")


class PieChart(Chart):
    """
    Child class that will implement a version of Template Methods
    """
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
