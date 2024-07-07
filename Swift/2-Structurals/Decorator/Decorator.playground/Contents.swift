import Foundation

// Base protocol with lowest common APIs
protocol Widget {
    func draw()
}

// Button is the core class to draw the widget
class Button: Widget {
    private let width: Int
    private let height: Int
    
    init(width: Int, height: Int) {
        self.width = width
        self.height = height
    }
    
    func draw() {
        print("Button: \(width), \(height)")
    }
}

// The Decorator class
class Decorator: Widget {
    private let widget: Widget
    
    init(widget: Widget) {
        self.widget = widget
    }
    
    func draw() {
        widget.draw() // Delegate execution
    }
}

class BorderDecorator: Decorator {
    override func draw() {
        super.draw()
        print("   BorderDecorator")
    }
}

class ButtonImageDecorator: Decorator {
    override func draw() {
        super.draw()
        print("   ButtonImageDecorator")
    }
}

// Usage
let btn: Widget = BorderDecorator(
    widget: ButtonImageDecorator(
        widget: Button(width: 44, height: 44)
    )
)

btn.draw()

/**
 Button: 44, 44
    ButtonImageDecorator
    BorderDecorator
 */
