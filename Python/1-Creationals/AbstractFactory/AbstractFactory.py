#!/usr/bin/env python3

"""
Provide an interface for creating families of related or dependent
objects without specifying their concrete classes.
"""


from abc import ABCMeta, abstractmethod


class Gadget(metaclass=ABCMeta):
    """
    Declare an interface for operations that create abstract product
    objects.
    """

    def __init__(self):
        pass

    @abstractmethod
    def sell_smart_phone(self):
        pass

    @abstractmethod
    def sell_smart_watch(self):
        pass


class Samsung(Gadget):
    """
    Implement the operations to create concrete product objects.
    """
    def sell_smart_phone(self):
        return GalaxySeries()

    def sell_smart_watch(self):
        return SamsungGearSeries()


class Apple(Gadget):
    """
    Implement the operations to create concrete product objects.
    """
    def sell_smart_phone(self):
        return IphoneSeries()

    def sell_smart_watch(self):
        return AppleWatchSeries()


class SmartPhone(metaclass=ABCMeta):
    """
    Declare an interface for a type of product object.
    """

    def __init__(self):
        pass

    @abstractmethod
    def calling_gadget(self, phone=""):
        pass


class SmartWatch(metaclass=ABCMeta):
    """
    Declare an interface for a type of product object.
    """

    def __init__(self):
        pass

    @abstractmethod
    def wearable_gadget(self, watch=""):
        pass


class GalaxySeries(SmartPhone):
    """
    Define a product object to be created by the corresponding concrete
    factory.
    Implement the AbstractProduct interface.
    """
    def calling_gadget(self, phone=""):
        print("Samsung Galaxy S8 Plus (Midnight Black, 64 GB) (4 GB RAM)\n"
              "Samsung Galaxy S7 Edge (Black Onyx, 32 GB) (4 GB RAM)\n"
              "Samsung Galaxy Note 5 64GB Single Sim-Gold(Gold, 64GB)")


class IphoneSeries(SmartPhone):
    """
    Define a product object to be created by the corresponding concrete
    factory.
    Implement the AbstractProduct interface.
    """
    def calling_gadget(self, phone=""):
        print("Apple iPhone 7 (Jet Black, 128 GB)\n"
              "Apple iPhone SE (Space Grey, 16 GB)\n"
              "Apple iPhone 5s (Silver, 16 GB)")


class SamsungGearSeries(SmartWatch):
    """
    Define a product object to be created by the corresponding concrete
    factory.
    Implement the AbstractProduct interface.
    """
    def wearable_gadget(self, watch=""):
        print("Samsung Gear S2 Silver Smartwatch  (Silver Strap Regular)\n"
              "Samsung Gear S2 Classic Platinum Smartwatch\n")


class AppleWatchSeries(SmartWatch):
    """
    Define a product object to be created by the corresponding concrete
    factory.
    Implement the AbstractProduct interface.
    """
    def wearable_gadget(self, watch=""):
        print("Apple Watch Series 2 - 42 mm Rose Gold Case with \
        Midnight Blue Sports Band  (Blue Strap Medium)")


class GadgetStore:
    def __init__(self):
        pass

    def store_gadgets(self):
        for store in [Apple(), Samsung()]:
            self.store = store
            self.SmartPhone = self.store.sell_smart_phone()
            self.SmartPhone.calling_gadget()
            self.SmartWatch = self.store.sell_smart_watch()
            self.SmartWatch.wearable_gadget()


def main():
    account = GadgetStore()
    account.store_gadgets()


if __name__ == "__main__":
    main()
