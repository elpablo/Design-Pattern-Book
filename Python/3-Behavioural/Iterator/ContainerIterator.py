

class ContainerIterator:
    """
    Iterator class used to iterate over the container's elements
    """
    def __init__(self, container):
        self._container = container
        self._index = 0

    def first(self):
        """
        It moves to point to the first item
        :return: None
        """
        self._index = 0

    def next(self):
        """
        It moves to point to the next item
        :return: None
        """
        self._index += 1

    def has_next(self):
        """
        It checks if there are other items
        :return:
        """
        return self._index != self._container._current_index + 1

    def current_item(self):
        """
        It accesses the content of the currently pointer item
        :return: The item at the current iterator's position
        """
        return self._container._items[self._index]
