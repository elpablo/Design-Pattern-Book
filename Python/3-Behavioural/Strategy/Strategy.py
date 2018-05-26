from abc import ABC, abstractmethod


class Strategy(ABC):
    def __init__(self, d):
        self._data = d

    @abstractmethod
    def serialize(self):
        pass


class OnDiskStrategy(Strategy):
    def serialize(self):
        print("Serialize data '%s' on disk" % self._data.value())


class OnCloudStrategy(Strategy):
    def serialize(self):
        print("Serialize data '%s' on cloud" % self._data.value())

