

class ObjectData:
    """
    Demo class used to demonstrate the Strategy pattern
    """
    def __init__(self, s):
        self._val = s

    def value(self):
        return self._val
