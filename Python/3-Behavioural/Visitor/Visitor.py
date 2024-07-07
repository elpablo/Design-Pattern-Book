from abc import ABC, abstractmethod


class Visitor(ABC):
    """
    Base abstract class that define the Visitor pattern's API
    """
    @abstractmethod
    def visit(self, page):
        """
        It will be used to 'visit' the model object
        :param page: Is the model object
        :return: None
        """
        pass


class UpperTextVisitor(Visitor):
    """
    Concrete class that implement a functionality applied to the Model using the Visitor Design Pattern
    """
    def __init__(self):
        self._str = ""

    def visit(self, page):
        """
        It apply the new function to the model
        :param page: The model on which will be applied the visitor
        :return: None
        """
        self._str = page.text().upper()

    def text(self):
        return self._str


class LowerTextVisitor(Visitor):
    """
    Concrete class that implement a functionality applied to the Model using the Visitor Design Pattern
    """
    def __init__(self):
        self._str = ""

    def visit(self, page):
        """
        It apply the new function to the model
        :param page: The model on which will be applied the visitor
        :return: None
        """
        self._str = page.text().lower()

    def text(self):
        return self._str
