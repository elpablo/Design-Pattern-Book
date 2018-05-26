#!/usr/bin/env python3

from Container import Container


def main():
    stack = Container()
    for i in range(1, 5):
        stack.push(i)

    container_iterator = stack.create_iterator()
    while container_iterator.has_next():
        print("Item: %d" % container_iterator.current_item())
        container_iterator.next()


if __name__ == '__main__':
    main()


"""
Output:

Item: 1
Item: 2
Item: 3
Item: 4
"""
