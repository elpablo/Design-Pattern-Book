import Foundation

// Implemented protocol (interface in C++)
protocol WidgetAbstractInterface {
    func createWidget()
}

// Protocol for internal implementation that Bridge uses
protocol ImplementationInterface {
    func setupWidget()
}

// The Bridge
class Bridge: WidgetAbstractInterface {
    private let implementation: ImplementationInterface
    
    init(implementation: ImplementationInterface) {
        self.implementation = implementation
    }
    
    func createWidget() {
        fatalError("This method must be overridden")
    }
}

// Different special cases of the interface
class Button: Bridge {
    override func createWidget() {
        print("Button on ", terminator: "")
        implementation.setupWidget()
    }
}

class TextField: Bridge {
    override func createWidget() {
        print("TextField on ", terminator: "")
        implementation.setupWidget()
    }
}

// Different background implementations
class Windows: ImplementationInterface {
    func setupWidget() {
        print("Windows...")
    }
}

class Linux: ImplementationInterface {
    func setupWidget() {
        print("Linux...")
    }
}

// Usage
let osWindows = Windows()
let osLinux = Linux()

// First case
var widget: WidgetAbstractInterface = Button(implementation: osWindows)
widget.createWidget()

widget = Button(implementation: osLinux)
widget.createWidget()

// Second case
widget = TextField(implementation: osWindows)
widget.createWidget()

widget = TextField(implementation: osLinux)
widget.createWidget()

/**
 Button on Windows...
 Button on Linux...
 TextField on Windows...
 TextField on Linux...
 */
