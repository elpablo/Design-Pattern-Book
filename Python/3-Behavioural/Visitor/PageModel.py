from abc import ABC, abstractmethod


class PageBase(ABC):
    @abstractmethod
    def accept(self, visitor):
        pass


class Page(PageBase):
    def accept(self, visitor):
        visitor.visit(self)

    def text(self):
        return "Page Text"
