#!/usr/bin/env python3
import math


class _ModelData:
    """
    Private Class Data variables cannot be modified
    by anyone externally to the ModelData class and their
    structure is hidden to the client code that use the
    Circle class
    """
    def __init__(self, radius, origin_x, origin_y):
        self.radius = radius
        self.origin = [origin_x, origin_y]

    def origin_x(self):
        return self.origin[0]

    def origin_y(self):
        return self.origin[1]


class Circle:
    def __init__(self, r, x, y):
        self.model = _ModelData(r, x, y)

    def circumference(self):
        return 2.0 * self.model.radius * math.pi

    def diameter(self):
        return 2.0 * self.model.radius

    def draw(self):
        # do something
        pass


def main():
    # Client code should in general be in another file.
    # Python uses underscore to mark a symbol as internal.
    # "from module import *" does not import underscore-prefixed symbols
    c = Circle(5, 0, 0)
    print("circumference: %f" % c.circumference())
    print("diameter: %f" % c.diameter())


if __name__ == "__main__":
    main()


"""
Output:

circumference: 31.415927
diameter: 10.000000

"""
