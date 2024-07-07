

class Model:
    """
    Demo model class to be observed using the Observer pattern
    """
    def __init__(self):
        self._observers = []
        self._value = 0

    def attach(self, obs):
        """
        Method used to attach the observer to the model
        :param obs: The observer
        :return: None
        """
        self._observers.append(obs)

    def notify(self):
        """
        It will (notify) call the update method of all the attached observers
        :return: None
        """
        for o in self._observers:
            o.update()

    def __setattr__(self, key, value):
        """
        It shows the notification process after a property update
        :return: None
        """
        super().__setattr__(key, value)
        self.notify()

    def set_value(self, v):
        """
        Demo method used to modify a model's property
        :param v: Is the new value
        :return: None
        """
        self._value = v

    def get_value(self):
        """
        Demo method used to return the updated value
        :return: The property's value
        """
        return self._value
