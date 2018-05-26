#!/usr/bin/env python3

from Model import Model
from Observer import DivObserver, ModObserver


def main():
    # Build the subject to be observed
    subject = Model()

    # Client configures the number and...
    div_obs_1 = DivObserver(subject, 4)
    div_obs_2 = DivObserver(subject, 3)

    # ...type of Observers
    mod_obs = ModObserver(subject, 3)

    # Change the subject’s value to trigger the notification for the observers
    print("New value to the model will trigger the observer's updates")
    subject.set_value(14)


if __name__ == '__main__':
    main()


"""
Output:

New value to the model will trigger the observer's updates
14.00 div 4.00 is 3.50
14.00 div 3.00 is 4.67
14.00 mod 3.00 is 2.00
"""
