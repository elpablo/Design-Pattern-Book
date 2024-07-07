from abc import ABC, abstractmethod


class PageBase(ABC):
    """
    Base abstract class of the model that has to be visited
    """
    @abstractmethod
    def accept(self, visitor):
        """
        It is the method used to accept a visitor that will visit the model
        :param visitor: Is the visitor to be accepted by the model
        :return: None
        """
        pass


class Page(PageBase):
    """
    Concrete class that will implement the accept of the visitor
    """
    def accept(self, visitor):
        """
        Accepting the visitor means that the visitor's visit method is called passing the model itself as argument
        :param visitor: Is the visitor that want to visit the model
        :return: None
        """
        visitor.visit(self)

    def text(self):
        return "Page Text"
