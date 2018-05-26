#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Character(ABC):
    """
    The 'Flyweight' abstract class
    """
    def __init__(self):
        self.symbol = ''
        self.width = 0
        self.height = 0
        self.ascent = 0
        self.descent = 0
        self.point_size = 0

    @abstractmethod
    def display(self, point_size):
        pass


class CharacterA(Character):
    """
    A 'ConcreteFlyweight' class
    """
    def __init__(self):
        Character.__init__(self)
        # Shared part between all the characters 'A' of a string
        self.symbol = 'A'
        self.width = 120
        self.height = 100
        self.ascent = 70
        self.descent = 0
        # initialise the not sharable content
        self.point_size = 0

    def display(self, point_size):
        self.point_size = point_size
        print("%s (point size %d)" % (self.symbol, self.point_size))


class CharacterB(Character):
    """
    B 'ConcreteFlyweight' class
    """

    def __init__(self):
        Character.__init__(self)
        # Shared part between all the characters 'B' of a string
        self.symbol = 'B'
        self.width = 140
        self.height = 100
        self.ascent = 72
        self.descent = 0
        # initialise the not sharable content
        self.point_size = 0

    def display(self, point_size):
        self.point_size = point_size
        print("%s (point size %d)" % (self.symbol, self.point_size))


# C, D, E,...


class CharacterZ(Character):
    """
    Z 'ConcreteFlyweight' class
    """

    def __init__(self):
        Character.__init__(self)
        # Shared part between all the characters 'Z' of a string
        self.symbol = 'Z'
        self.width = 100
        self.height = 100
        self.ascent = 68
        self.descent = 0
        # initialise the not sharable content
        self.point_size = 0

    def display(self, point_size):
        self.point_size = point_size
        print("%s (point size %d)" % (self.symbol, self.point_size))


class CharacterFactory:
    """
    The 'FlyweightFactory' class
    """
    def __init__(self):
        self.characters = {}

    def get_character(self, key):
        character = None
        if self.characters.keys().__contains__(key):
            character = self.characters[key]
        else:
            if key == 'A':
                character = CharacterA()
            elif key == 'B':
                character = CharacterB()
            # ...
            elif key == 'Z':
                character = CharacterZ()
            else:
                print("Not Implemented")
                raise Exception("Character not implemented")

            self.characters[key] = character

        return character


def main():
    # Client code
    document = "AAZZBBZB"

    factory = CharacterFactory()

    # extrinsic state
    point_size = 10

    for c in document:
        point_size += 1
        character = factory.get_character(c)
        character.display(point_size)


if __name__ == '__main__':
    main()

"""
Output:

A (point size 11)
A (point size 12)
Z (point size 13)
Z (point size 14)
B (point size 15)
B (point size 16)
Z (point size 17)
B (point size 18)
"""
