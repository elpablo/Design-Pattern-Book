from ContainerIterator import ContainerIterator


class Container:
    """
    Class representing the container of items to be iterated
    """
    def __init__(self):
        self._current_index = -1
        self._items = []

    def push(self, val):
        """
        It adds a new item into the container
        :param val: the item to be added
        :return: None
        """
        self._items.append(val)
        self._current_index = len(self._items) - 1

    def pop(self):
        """
        It removes the item at the current index from the container
        :return: The removed item
        """
        item = self._items[self._current_index]
        self._current_index -= 1
        return item

    def is_empty(self):
        """
        It checks if the container is empty or no
        :return: True if the container is empty, False otherwise
        """
        return self._current_index < 0

    def create_iterator(self):
        """
        It creates a new iterator for the container itself
        :return: The instance of the iterator
        """
        return ContainerIterator(self)
