from abc import ABC, abstractmethod


class State(ABC):
    def __init__(self):
        self.transitions = None

    @abstractmethod
    def run(self):
        pass

    def next(self, act):
        """
        Determine which is the next state associated to the given action
        :param act: is the action required
        :return: The next state object to be executed by the StateMachine or
        rise an Exception if the action is not contained in the available state's transitions
        """
        if self.transitions.keys().__contains__(act):
            return self.transitions[act]
        else:
            raise Exception("Transition not supported for current state")
