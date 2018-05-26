#!/usr/bin/env python3

from ObjectData import ObjectData
from Strategy import OnDiskStrategy
from Strategy import OnCloudStrategy


class Serializer:
    def __init__(self):
        self._strategy = None

    def set_strategy(self, s):
        self._strategy = s

    def save_data(self):
        self._strategy.serialize()


def main():
    # We have our model that has to be saved
    obj = ObjectData("42")

    disk = OnDiskStrategy(obj)

    serializer = Serializer()
    serializer.set_strategy(disk)
    serializer.save_data()

    cloud = OnCloudStrategy(obj)
    serializer.set_strategy(cloud)
    serializer.save_data()


if __name__ == '__main__':
    main()


"""
Output:

Serialize data '42' on local disk.
Serialize data '42' on cloud.

"""
