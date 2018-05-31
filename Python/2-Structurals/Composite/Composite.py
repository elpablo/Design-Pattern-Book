#!/usr/bin/env python3

from abc import ABC, abstractmethod


class FilterInterface(ABC):
    """
    "interface" Filter class (lowest common denominator between single and grouped objects)
    """
    def __init__(self):
        pass

    @abstractmethod
    def apply_filter(self):
        pass


class Filter(FilterInterface):
    def __init__(self, val):
        FilterInterface.__init__(self)
        self.filter_param = val

    def apply_filter(self):
        print("Apply filter with param %d" % self.filter_param)


class FilterGroup(FilterInterface):
    def __init__(self):
        FilterInterface.__init__(self)
        self.filters = []

    def add_filter(self, f):
        self.filters.append(f)

    def apply_filter(self):
        for f in self.filters:
            f.apply_filter()


def main():
    # Setup some single and composite filters
    # ...

    # Build a single filter
    single = Filter(42)

    # Setup a group of filters into a group
    group = FilterGroup()
    for i in range(0, 4):
        group.add_filter(Filter(i))

    # Build a group of group of filters
    mega_group = FilterGroup()
    group2 = FilterGroup()
    for i in range(5, 10):
        group2.add_filter(Filter(i))
    mega_group.add_filter(group2)

    # Now we can use the base class API for single filters or groups
    single.apply_filter()
    print("")

    group.apply_filter()
    print("")

    mega_group.apply_filter()
    print("")


if __name__ == "__main__":
    main()


"""
Output:

Apply filter with param 42

Apply filter with param 0
Apply filter with param 1
Apply filter with param 2
Apply filter with param 3

Apply filter with param 5
Apply filter with param 6
Apply filter with param 7
Apply filter with param 8
Apply filter with param 9

"""
