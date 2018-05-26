

class StateMachine:
    def __init__(self, initial_state):
        # Store the initial state
        self._current_state = initial_state
        # ...and ask run it
        self._current_state.run()

    def run(self, act):
        """
        It allows to execute the new state associated to the given action
        :param act: is the proposed action to execute
        :return: None
        """
        # retrieve the nex state associated to the given action
        self._current_state = self._current_state.next(act)
        # ...and run it
        self._current_state.run()
