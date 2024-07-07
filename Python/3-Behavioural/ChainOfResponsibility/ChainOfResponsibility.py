#!/usr/bin/env python3


class EventHandler:
    """
    Base class of the event's handlers. It defines the handler's API
    """
    def __init__(self):
        self._next = None

    def set_next(self, handler):
        self._next = handler

    def add(self, handler):
        """
        It adds a given handler to the chain assigning it to the _next property
        :param handler: the handler to put in chain
        :return: None
        """
        if self._next is None:
            self._next = handler
        else:
            self._next.add(handler)

    def handle(self, ev):
        """
        It allows to handle the given event
        :param ev: the event to handle
        :return: None
        """
        if self._next is None:
            print("Event %d not handled!!", ev)
        else:
            self._next.handle(ev)


class MouseEventHandler(EventHandler):
    def handle(self, i):
        # Let's decide which is the rule for handling the Mouse events
        if 3 <= i < 5:
            print("MouseEvent handled %d\n" % i)
        else:
            print("MouseEvent passed")
            EventHandler.handle(self, i)


class KeyEventHandler(EventHandler):
    def handle(self, i):
        # Let's decide which is the rule for handling the Key events
        if i >= 5:
            print("KeyEventHandler handled %d\n" % i)
        else:
            print("KeyEventHandler passed")
            EventHandler.handle(self, i)


class InteractionEventHandler(EventHandler):
    def handle(self, i):
        # Let's decide which is the rule for handling the Interaction events
        if i <= 2:
            print("InteractionEventHandler handled %d\n" % i)
        else:
            print("InteractionEventHandler passed")
            EventHandler.handle(self, i)


def main():
    # Create some handlers
    main_ui = MouseEventHandler()
    text_field = KeyEventHandler()
    text_area = InteractionEventHandler()

    # ... and then chain them together
    main_ui.add(text_field)
    main_ui.add(text_area)
    # the next call will create a loop with the first event handler
    # Pay attention to be sure that all the handlers are able to
    # handle the events, otherwise you'll get a stack overflow.
    text_area.set_next(main_ui)

    # Now make some calls to request the event's handling
    for i in range(1, 10):
        main_ui.handle(i)


if __name__ == '__main__':
    main()


"""
Output:

MouseEvent passed
KeyEventHandler passed
InteractionEventHandler handled 1

MouseEvent passed
KeyEventHandler passed
InteractionEventHandler handled 2

MouseEvent handled 3

MouseEvent handled 4

MouseEvent passed
KeyEventHandler handled 5

MouseEvent passed
KeyEventHandler handled 6

MouseEvent passed
KeyEventHandler handled 7

MouseEvent passed
KeyEventHandler handled 8

MouseEvent passed
KeyEventHandler handled 9

"""
