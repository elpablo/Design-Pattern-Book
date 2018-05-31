from abc import ABC, abstractmethod


class Strategy(ABC):
    """
    Base class of the strategy pattern
    """
    def __init__(self, d):
        self._data = d

    @abstractmethod
    def serialize(self):
        """
        It is the method that will be re-implemented by the child classes with their own specialization
        :return: None
        """
        pass


class OnDiskStrategy(Strategy):
    def serialize(self):
        print("Serialize data '%s' on disk" % self._data.value())


class OnCloudStrategy(Strategy):
    def serialize(self):
        print("Serialize data '%s' on cloud" % self._data.value())

