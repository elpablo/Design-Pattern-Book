#!/usr/bin/env python3

_monitor = None


class Monitor:
    def __init__(self):
        self.parameter = 3

    def do_something(self):
        print('Do something with param: %d' % self.parameter)


def shared_monitor():
    """
    It checks that the instance of Monitor has been created or not and returns it to the caller
    :return: the unique instance of the Monitor
    """
    global _monitor
    if _monitor is None:
        _monitor = Monitor()

    return _monitor


def main():
    shared_monitor().do_something()


if __name__ == "__main__":
    main()
