#!/usr/bin/env python3

from abc import ABC, abstractmethod


class ColorInterface(ABC):
    """
    Abstract class for the old style color with RGB channels
    """
    def __init__(self):
        pass

    @abstractmethod
    def red(self):
        pass

    @abstractmethod
    def green(self):
        pass

    @abstractmethod
    def blue(self):
        pass


class RGBColor(ColorInterface):
    """
    Concrete class of the old style color API used in old code for example
    """
    def red(self):
        return 1.0

    def green(self):
        return 0.87

    def blue(self):
        return 0.0


class RGBAColor(ABC):
    """
    Abstract class for the new type of color with the Alpha channel
    """
    def __init__(self):
        pass

    @abstractmethod
    def red(self):
        pass

    @abstractmethod
    def green(self):
        pass

    @abstractmethod
    def blue(self):
        pass

    @abstractmethod
    def alpha(self):
        pass


class Adapter(RGBAColor):
    """
    Adapter class used to adapt the old style color with the new one
    """
    def __init__(self):
        RGBAColor.__init__(self)
        self.old_rgb_color = None

    def set_color(self, c):
        """
        Assign the old style object that needs to be adapted
        :param c: the old style color
        :return: None
        """
        self.old_rgb_color = c

    def red(self):
        return self.old_rgb_color.red()

    def green(self):
        return self.old_rgb_color.green()

    def blue(self):
        return self.old_rgb_color.blue()

    def alpha(self):
        """
        Adapter method to the new color's API
        :return: A default value for the new API missing in the old style API
        """
        return 1.0


class ColorSpaceFilter:
    """
    Example object using the new color with the new API
    """
    def __init__(self):
        self.rgba_color = None

    def set_color(self, c):
        self.rgba_color = c

    def apply(self):
        print("Applying color filtering...")
        print("red: ", self.rgba_color.red())
        print("green: ", self.rgba_color.green())
        print("blue: ", self.rgba_color.blue())
        print("alpha: ", self.rgba_color.alpha())


def main():
    # We have an old style color that has to be passed to a
    # new filter which accept only a new style color
    old_style_color = RGBColor()

    # Build the adapter between the two color styles
    adapter = Adapter()
    adapter.set_color(old_style_color)

    # Build the filter we have to use with the adapted old style color
    color_filter = ColorSpaceFilter()
    color_filter.set_color(adapter)

    # Apply the filter using the old style adapted color
    color_filter.apply()


if __name__ == "__main__":
    main()


"""
Output:

Applying color filtering...
red:  1.0
green:  0.87
blue:  0.0
alpha:  1.0

"""
