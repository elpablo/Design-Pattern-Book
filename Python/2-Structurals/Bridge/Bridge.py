#!/usr/bin/env python3

from abc import ABC, abstractmethod


class WidgetAbstractInterface(ABC):
    """
    Abstract class for the widget's API
    """
    def __init__(self):
        pass

    @abstractmethod
    def create_widget(self):
        pass


class ImplementationInterface(ABC):
    """
    Abstract class for the widget's implementation
    """
    def __init__(self):
        pass

    @abstractmethod
    def setup_widget(self):
        pass


class Bridge(WidgetAbstractInterface):
    """
    The bridge abstract class
    """
    def __init__(self, implementation):
        WidgetAbstractInterface.__init__(self)
        self.implementation_interface = implementation

    def create_widget(self):
        pass


class Button(Bridge):
    """
    Button interface over different implementations
    """
    def create_widget(self):
        print("Button on ")
        self.implementation_interface.setup_widget()


class TextField(Bridge):
    """
    Text field interface over different implementations
    """
    def create_widget(self):
        print("TextField on ")
        self.implementation_interface.setup_widget()


class Windows(ImplementationInterface):
    """
    Widget implementation on Windows
    """
    def setup_widget(self):
        print("Windows...\n")


class Linux(ImplementationInterface):
    """
    Widget implementation on Linux
    """
    def setup_widget(self):
        print("Linux...\n")


def main():
    os_windows = Windows()
    os_linux = Linux()

    # Create a button for the Windows OS
    win_button = Button(os_windows)
    win_button.create_widget()

    # Create a button for the Linux OS
    lin_button = Button(os_linux)
    lin_button.create_widget()

    # Create a TextField for the Windows OS
    win_button = TextField(os_windows)
    win_button.create_widget()

    # Create a TextField for the Linux OS
    lin_button = TextField(os_linux)
    lin_button.create_widget()


if __name__ == "__main__":
    main()


"""
Output:

Button on 
Windows...

Button on 
Linux...

TextField on 
Windows...

TextField on 
Linux...

"""
