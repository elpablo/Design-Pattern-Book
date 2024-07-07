#!/usr/bin/env python3


class Monitor:
    """
    This is the singleton (Borg in Python) class with shared state between instances
    """
    __shared_state = {}

    def __init__(self):
        self.__dict__ = self.__shared_state
        self.parameter = 3

    def do_something(self):
        print('Do something with param: %d' % self.parameter)


def main():
    # create 2 variables with the instance of the Monitor Singleton (Borg in Python)
    m = Monitor()
    m2 = Monitor()

    # Print some text with the value of the 'parameter' variable (default 3)
    m.do_something()
    # alter the value of 'parameter' on the first variable
    m.parameter = 5

    # Print again the text with the value of the 'parameter' variable (5 on both variables)
    m2.do_something()
    m.do_something()


if __name__ == "__main__":
    main()

"""
Output:

Do something with param: 3
Do something with param: 5
Do something with param: 5

"""
