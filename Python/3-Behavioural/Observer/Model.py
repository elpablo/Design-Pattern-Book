

class Model:
    def __init__(self):
        self._observers = []
        self._value = 0

    def attach(self, obs):
        self._observers.append(obs)

    def notify(self):
        for o in self._observers:
            o.update()

    def set_value(self, v):
        self._value = v
        self.notify()

    def get_value(self):
        return self._value
