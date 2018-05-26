

class ContainerIterator:
    def __init__(self, container):
        self._container = container
        self._index = 0

    def first(self):
        self._index = 0

    def next(self):
        self._index += 1

    def has_next(self):
        return self._index != self._container._current_index + 1

    def current_item(self):
        return self._container._items[self._index]
