from ContainerIterator import ContainerIterator


class Container:
    def __init__(self):
        self._current_index = -1
        self._items = []

    def push(self, val):
        self._items.append(val)
        self._current_index = len(self._items) - 1

    def pop(self):
        item = self._items[self._current_index]
        self._current_index -= 1
        return item

    def is_empty(self):
        return self._current_index < 0

    def create_iterator(self):
        return ContainerIterator(self)
