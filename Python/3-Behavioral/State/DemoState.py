#!/usr/bin/env python3

from StateMachine import StateMachine
from State import State

###############################################################
# Custom states and transitions


class RunningState(State):
    def __init__(self):
        State.__init__(self)

    def run(self):
        # Execute the code associated to the state
        print("Run\n")

    def next(self, act):
        # Lazy initialization of the state's transitions
        if self.transitions is None:
            # setup the transitions; 0 => Stop state, 1 => Loop-back to the current state
            self.transitions = {
                0: StoppedState(),
                1: self
            }
        # call the superclass 'next' method to return the next state associated to the proposed action
        return State.next(self, act)


class StoppedState(State):
    def __init__(self):
        State.__init__(self)

    def run(self):
        # Execute the code associated to the state
        print("Stop\n")

    def next(self, act):
        # Lazy initialization of the state's transitions
        if self.transitions is None:
            # setup the transitions; 0 => Loop-back to the current state, 1 => Run state
            self.transitions = {
                0: self,
                1: RunningState()
            }
        # call the superclass 'next' method to return the next state associated to the proposed action
        return State.next(self, act)

###############################################################


def main():
    # Setup the StateMachine with the StoppedState as initial state
    sm = StateMachine(StoppedState())

    num = 0
    while num != 2:
        num = int(input('0 to Stop, 1 to Run, 2 to Exit: \n'))
        if num == 0 or num == 1:
            sm.run(num)


if __name__ == '__main__':
    main()


"""
Output:

Stop

0 to Stop, 1 to Run, 2 to Exit: 
0
Stop

0 to Stop, 1 to Run, 2 to Exit: 
1
Run

0 to Stop, 1 to Run, 2 to Exit: 
1
Run

0 to Stop, 1 to Run, 2 to Exit: 
0
Stop

0 to Stop, 1 to Run, 2 to Exit: 
0
Stop

0 to Stop, 1 to Run, 2 to Exit: 
2

Process finished with exit code 0

"""
