from abc import ABC, abstractmethod


class Observer(ABC):
    """

    """
    def __init__(self, model, val):
        self._divisor = val
        self._model = model
        # Observers register themselves with the Model
        self._model.attach(self)

    @abstractmethod
    def update(self):
        pass


class DivObserver(Observer):
    def update(self):
        # "Pull" information of interest
        v = self._model.get_value()
        res = v / self._divisor
        print("%.2f div %.2f is %.2f" % (v, self._divisor, res))


class ModObserver(Observer):
    def update(self):
        # "Pull" information of interest
        v = self._model.get_value()
        res = v % self._divisor
        print("%.2f mod %.2f is %.2f" % (v, self._divisor, res))
