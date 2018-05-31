#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Order:
    """
    Fake class used with the command pattern
    """
    def __init__(self, quantity):
        self._quantity = quantity

    def buy(self):
        """
        This is the method that will be used to be called by the command pattern
        :return:
        """
        print("Buy %d Items" % self._quantity)


class Command(ABC):
    """
    Base abstract class used to define the API for the command
    """
    def __init__(self):
        pass

    @abstractmethod
    def execute(self):
        """
        Method used to execute the command. The method signature require that the destination action will have the
        similar signature
        :return: None
        """
        pass


class SimpleCommand(Command):
    def __init__(self, action):
        Command.__init__(self)
        self._action = action

    def execute(self):
        print("Running Simple command...")
        self._action()


class MacroCommand(Command):
    def __init__(self):
        Command.__init__(self)
        self._commands = []

    def add_command(self, c):
        self._commands.append(c)

    def execute(self):
        print("\nRunning macro command...")
        for c in self._commands:
            c.execute()


def main():
    order = Order(5)

    simple_command = SimpleCommand(order.buy)

    buy_twice = MacroCommand()
    buy_twice.add_command(simple_command)
    buy_twice.add_command(simple_command)

    commands = [simple_command, buy_twice]
    for c in commands:
        c.execute()


if __name__ == '__main__':
    main()


"""
Output:

Running Simple command...
Buy 5 Items

Running macro command...
Running Simple command...
Buy 5 Items
Running Simple command...
Buy 5 Items
"""
