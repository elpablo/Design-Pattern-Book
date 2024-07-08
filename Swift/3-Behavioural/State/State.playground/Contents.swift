import Foundation
import PlaygroundSupport

class StateMachine {
    private var currentState: State

    init() {
        currentState = StoppedState()
    }

    func setCurrent(_ state: State) {
        currentState = state
    }

    func run() {
        currentState.running(self)
    }

    func stop() {
        currentState.stopped(self)
    }
}

protocol State {
    func running(_ machine: StateMachine)
    func stopped(_ machine: StateMachine)
}

extension State {
    func running(_ machine: StateMachine) {
        print("   already Running")
    }

    func stopped(_ machine: StateMachine) {
        print("   already Stopped")
    }
}

class RunningState: State {
    func stopped(_ machine: StateMachine) {
        print("   transition RunningState -> StoppedState")
        machine.setCurrent(StoppedState())
    }
}

class StoppedState: State {
    func running(_ machine: StateMachine) {
        print("   transition StoppedState -> RunningState")
        machine.setCurrent(RunningState())
    }
}

// Simulation of the main program logic
let fullStateStateMachine = StateMachine()

func simulateInput(_ input: Int) {
    print("Input: \(input)")
    if input == 0 {
        fullStateStateMachine.stop()
    } else if input == 1 {
        fullStateStateMachine.run()
    }
}

// Simulate a sequence of inputs
let inputs = [0, 1, 1, 0, 1, 0, 0]
for input in inputs {
    simulateInput(input)
}
