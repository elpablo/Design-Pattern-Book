#!/usr/bin/env python3

from abc import ABC, abstractmethod


###############################################################################################
# Interpreter grammar definition
#

class ExpressionInterpreter(ABC):
    """
    Base class used to interpret the grammar expressions
    """
    @abstractmethod
    def interpret(self):
        """
        It is the signature of the method used to interpret the different grammar expressions
        :return: The interpreted expression
        """
        pass


class NumberExpression(ExpressionInterpreter):
    """
    Interpreter class used to interpret numerical symbols
    """
    def __init__(self, n):
        self._number = n

    def interpret(self):
        return self._number


class AddExpression(ExpressionInterpreter):
    """
    Interpreter class used to interpret add expressions
    """
    def __init__(self, left_expression, right_expression):
        self._left = left_expression
        self._right = right_expression

    def interpret(self):
        return self._left.interpret() + self._right.interpret()


class SubtractExpression(ExpressionInterpreter):
    """
    Interpreter class used to interpret subtract expressions
    """
    def __init__(self, left_expression, right_expression):
        self._left = left_expression
        self._right = right_expression

    def interpret(self):
        return self._left.interpret() - self._right.interpret()

###############################################################################################


class TokenContext:
    """
    Class used to manage the context of the input document splitting it into simpler expressions
    and use the interpreter pattern to decode it
    """
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
    # Create a context
    context = TokenContext("+ - 10 2 3")
    expression = context.read_token()
    # call the interpreter pattern to decode it and print the result
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
