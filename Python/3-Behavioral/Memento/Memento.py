#!/usr/bin/env python3


class Memento:
    def __init__(self, val):
        self._state = val


class Wallet:
    def __init__(self, val):
        self._value = val

    def deposit(self):
        self._value *= 2.0

    def withdraw(self):
        self._value /= 2.0

    def get_balance(self):
        return self._value

    def create_memento(self):
        return Memento(self._value)

    def assign_memento(self, m):
        self._value = m._state


def main():
    wallet = Wallet(1000)
    wallet.deposit()

    print("Current Wallet balance: %.2f" % wallet.get_balance())

    # Store the current state of the wallet object
    memento = wallet.create_memento()

    wallet.withdraw()
    print("Wallet balance after withdraw: %.2f" % wallet.get_balance())

    # restore the previous wallet's state
    wallet.assign_memento(memento)
    print("Restore Wallet balance: %.2f" % wallet.get_balance())


if __name__ == '__main__':
    main()


"""
Output:

Current Wallet balance: 2000.00
Wallet balance after withdraw: 1000.00
Restore Wallet balance: 2000.00
"""
