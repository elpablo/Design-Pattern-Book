#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Item(ABC):
    """
    It defines the common API of the NullObject and a valid Item object
    """
    def __init__(self):
        pass

    @abstractmethod
    def do_something(self):
        pass


class FileItem(Item):
    def do_something(self):
        return "Calculate file's checksum..."


class NullItem(Item):
    def do_something(self):
        pass


def main():
    items = [FileItem(), NullItem()]

    print("Item 0 (Active): %s" % items[0].do_something())
    print("Item 1 (Null): %s" % items[1].do_something())


if __name__ == '__main__':
    main()


"""
Output:

Item 0 (Active): Calculate file's checksum...
Item 1 (Null): None
"""
