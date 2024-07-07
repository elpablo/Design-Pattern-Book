from abc import ABC, abstractmethod


class Observer(ABC):
    """
    Base class of the observer objects
    """
    def __init__(self, model, val):
        """
        The model is passed through the observer initialization method, so to be immediately connected with it.
        The 'val' argument is purely demonstrative. It can be something different in a real use case or
        could not be present at all
        :param model: The model to be observed
        :param val: A demo argument
        """
        self._divisor = val
        self._model = model
        # Observers register themselves with the Model
        self._model.attach(self)

    @abstractmethod
    def update(self):
        """
        It is the method called when the model changes
        :return: None
        """
        pass


class DivObserver(Observer):
    """
    An example of concrete implementation of the observer pattern
    """
    def update(self):
        """
        It calculates the division between the updated model value and the divisor observer's property
        :return:
        """
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
