#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Filter(ABC):
    """
    Base class for the prototype pattern
    """
    def __init__(self):
        pass

    @abstractmethod
    def clone(self):
        """
        Method used to generate the cloned instances
        :return:
        """
        pass

    @abstractmethod
    def apply_filter(self):
        """
        Method used to demonstrate the execution of different filters
        :return: None
        """
        pass


class GaussianBlur(Filter):
    def clone(self):
        return GaussianBlur()

    def apply_filter(self):
        print("GaussianBlur: applying filter...")


class Pixelate(Filter):
    def clone(self):
        return Pixelate()

    def apply_filter(self):
        print("Pixelate: applying filter...")


class Threshold(Filter):
    def clone(self):
        return Threshold()

    def apply_filter(self):
        print("Threshold: applying filter...")


class Factory(ABC):
    """
    Factory used to create objects from the corresponding prototype
    """
    prototypes = [GaussianBlur(), Pixelate(), Threshold()]

    @staticmethod
    def make_filter(index):
        return Factory.prototypes[index].clone()


def main():
    # Create some filters
    # 0 => GaussianBlur, 1 => Pixelate, 2 => Threshold
    filters = [Factory.make_filter(0), Factory.make_filter(2), Factory.make_filter(1)]

    for f in filters:
        f.apply_filter()


if __name__ == "__main__":
    main()


"""
Output:

GaussianBlur: applying filter...
Threshold: applying filter...
Pixelate: applying filter...

"""
