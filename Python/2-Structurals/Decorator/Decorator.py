#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Widget(ABC):
    """
    Base class with lowest common APIs
    """
    def __init__(self):
        pass

    @abstractmethod
    def draw(self):
        pass


class Button(Widget):
    """
    Button is the core class to draw the widget
    """
    def __init__(self, w, h):
        Widget.__init__(self)
        self.width = w
        self.height = h

    def draw(self):
        print("Drawing button of width: %d and height: %d" % (self.width, self.height))


class Decorator(Widget):
    """
    The inheritance from the Widget base class gives the "is a" relationship
    """
    def __init__(self, w):
        Widget.__init__(self)
        # "has a" relationship
        self.widget = w

    def draw(self):
        # Delegate execution
        self.widget.draw()


class BorderDecorator(Decorator):
    """
    Optional decoration
    """
    def draw(self):
        Decorator.draw(self)
        print("   decorate with border")


class ButtonImageDecorator(Decorator):
    """
    Optional decoration
    """
    def draw(self):
        Decorator.draw(self)
        print("   decorate with image icon")


def main():
    # Create a Button and decorate it with an image icon and a border
    # The decoration chain is read from inner class to the outer
    btn = BorderDecorator(ButtonImageDecorator(Button(44, 44)))
    btn.draw()


if __name__ == "__main__":
    main()


"""
Output:

Drawing button of width: 44 and height: 44
   decorate with image icon
   decorate with border

"""
