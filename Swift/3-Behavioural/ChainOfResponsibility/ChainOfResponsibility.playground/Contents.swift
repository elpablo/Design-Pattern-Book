import Foundation

class EventHandler {
    var next: EventHandler?
    
    func setNext(_ n: EventHandler) {
        next = n
    }
    
    func add(_ n: EventHandler) {
        if let next = next {
            next.add(n)
        } else {
            next = n
        }
    }
    
    func handle(_ i: Int) {
        next?.handle(i)
    }
}

class MouseEventHandler: EventHandler {
    override func handle(_ i: Int) {
        if Int.random(in: 0...2) != 0 {
            print("MouseEvent passed \(i)  ", terminator: "")
            super.handle(i)
        } else {
            print("MouseEvent handled \(i)  ", terminator: "")
        }
    }
}

class KeyEventHandler: EventHandler {
    override func handle(_ i: Int) {
        if Int.random(in: 0...2) != 0 {
            print("KeyEvent passed \(i)  ", terminator: "")
            super.handle(i)
        } else {
            print("KeyEvent handled \(i)  ", terminator: "")
        }
    }
}

class InteractionEventHandler: EventHandler {
    override func handle(_ i: Int) {
        if Int.random(in: 0...2) != 0 {
            print("InteractionEvent passed \(i)  ", terminator: "")
            super.handle(i)
        } else {
            print("InteractionEvent handled \(i)  ", terminator: "")
        }
    }
}

// Client code
let mainUI = MouseEventHandler()
let textField = KeyEventHandler()
let textArea = InteractionEventHandler()

mainUI.add(textField)
mainUI.add(textArea)
textArea.setNext(mainUI)

for i in 1...9 {
    mainUI.handle(i)
    print()
}

/**
 MouseEvent passed 1  KeyEvent passed 1  InteractionEvent handled 1
 MouseEvent handled 2
 MouseEvent passed 3  KeyEvent handled 3
 MouseEvent passed 4  KeyEvent passed 4  InteractionEvent passed 4  MouseEvent handled 4
 MouseEvent handled 5
 MouseEvent passed 6  KeyEvent handled 6
 MouseEvent passed 7  KeyEvent passed 7  InteractionEvent handled 7
 MouseEvent handled 8
 MouseEvent passed 9  KeyEvent passed 9  InteractionEvent handled 9
 */
