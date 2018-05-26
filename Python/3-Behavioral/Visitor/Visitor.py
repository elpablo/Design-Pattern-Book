from abc import ABC, abstractmethod


class Visitor(ABC):
    @abstractmethod
    def visit(self, page):
        pass


class UpperTextVisitor(Visitor):
    def __init__(self):
        self._str = ""

    def visit(self, page):
        self._str = page.text().upper()

    def text(self):
        return self._str


class LowerTextVisitor(Visitor):
    def __init__(self):
        self._str = ""

    def visit(self, page):
        self._str = page.text().lower()

    def text(self):
        return self._str
