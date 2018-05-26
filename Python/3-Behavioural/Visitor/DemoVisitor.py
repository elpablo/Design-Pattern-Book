#!/usr/bin/env python3

from PageModel import Page
from Visitor import UpperTextVisitor, LowerTextVisitor


def main():
    page = Page()

    up = UpperTextVisitor()
    low = LowerTextVisitor()

    page.accept(up)
    print("Visited Uppercase text: %s" % up.text())
    page.accept(low)
    print("Visited Lowercase text: %s" % low.text())


if __name__ == '__main__':
    main()


"""
Output:

 Visited Uppercase text: PAGE TEXT
 Visited Lowercase text: page text

"""
