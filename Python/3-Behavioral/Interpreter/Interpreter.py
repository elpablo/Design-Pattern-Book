#!/usr/bin/env python3

from abc import ABC, abstractmethod


###############################################################################################
# Interpreter grammar definition
#

class ExpressionInterpreter(ABC):
    @abstractmethod
    def interpret(self):
        pass


class NumberExpression(ExpressionInterpreter):
    def __init__(self, n):
        self._number = n

    def interpret(self):
        return self._number


class AddExpression(ExpressionInterpreter):
    def __init__(self, left_expression, right_expression):
        self._left = left_expression
        self._right = right_expression

    def interpret(self):
        return self._left.interpret() + self._right.interpret()


class SubtractExpression(ExpressionInterpreter):
    def __init__(self, left_expression, right_expression):
        self._left = left_expression
        self._right = right_expression

    def interpret(self):
        return self._left.interpret() - self._right.interpret()

###############################################################################################


class TokenContext:
    def __init__(self, token):
        self._tokenList = token.split()

    def read_token(self):
        return self._read_next_token()

    def _read_next_token(self):
        token = self._tokenList[0]
        if token.isnumeric():
            self._tokenList.__delitem__(0)
            return NumberExpression(int(token))
        else:
            return self._read_non_terminal()

    def _read_non_terminal(self):
        # Read the symbol
        token = self._tokenList[0]
        self._tokenList.__delitem__(0)
        # read left expression
        left = self._read_next_token()
        # read right expression
        right = self._read_next_token()

        if token == "+":
            return AddExpression(left, right)
        elif token == "-":
            return SubtractExpression(left, right)
        else:
            return None


def main():
    context = TokenContext("+ - 10 2 3")
    expression = context.read_token()
    print(expression.interpret())  # (10 - 2) + 3 = 11

    context = TokenContext("- + 10 5 - 8 2")
    expression = context.read_token()
    print(expression.interpret())  # (10 + 5) - (8 - 2) = 9


if __name__ == '__main__':
    main()


"""
Output:

11
9

"""
