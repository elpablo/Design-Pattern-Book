#!/usr/bin/env python3

from abc import ABC, abstractmethod


class Order:
    """
    Fake class used with the command pattern
    """
    def buy(self, quantity):
        print("Buy %d Items" % quantity)


class Command(ABC):
    """
    Base abstract class used to define the API for the command
    """
    def __init__(self):
        pass

    @abstractmethod
    def execute(self, val):
        pass


class SimpleCommand(Command):
    def __init__(self, action):
        Command.__init__(self)
        self._action = action

    def execute(self, val):
        print("Running Simple command...")
        self._action(val)


class MacroCommand(Command):
    def __init__(self):
        Command.__init__(self)
        self._commands = []

    def add_command(self, c):
        self._commands.append(c)

    def execute(self, val):
        print("\nRunning macro command...")
        for c in self._commands:
            c.execute(val)


def main():
    order = Order()

    simple_command = SimpleCommand(order.buy)
    buy_twice = MacroCommand()
    buy_twice.add_command(simple_command)
    buy_twice.add_command(simple_command)

    commands = [simple_command, buy_twice]
    for c in commands:
        c.execute(5)


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
