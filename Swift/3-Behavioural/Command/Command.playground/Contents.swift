import Foundation

class Order {
    func buy(_ quantity: inout Int) {
        print("Buy \(quantity) Items")
    }
}

protocol Command {
    func execute(_ num: inout Int)
}

class SimpleCommand: Command {
    typealias Action = (Order) -> (inout Int) -> Void
    
    private let receiver: Order
    private let action: Action
    
    init(_ receiver: Order, _ action: @escaping Action) {
        self.receiver = receiver
        self.action = action
    }
    
    func execute(_ num: inout Int) {
        action(receiver)(&num)
    }
}

class MacroCommand: Command {
    private var list: [Command] = []
    
    func add(_ cmd: Command) {
        list.append(cmd)
    }
    
    func execute(_ num: inout Int) {
        for command in list {
            command.execute(&num)
        }
    }
}

// Playground simulation
let object = Order()
var commands: [Command] = []

let simpleCommand = SimpleCommand(object, Order.buy)
commands.append(simpleCommand)

let buyTwice = MacroCommand()
buyTwice.add(simpleCommand)
buyTwice.add(simpleCommand)
commands.append(buyTwice)

func simulateOrder(quantity: Int, times: Int) {
    print("Order: \(quantity)")
    print("Times (1 => 1x, 2 => 2x): \(times)")
    
    if times == 1 || times == 2 {
        var num = quantity
        commands[times - 1].execute(&num)
    }
    print()
}

// Simulate a sequence of orders
simulateOrder(quantity: 3, times: 1)
simulateOrder(quantity: 3, times: 2)
simulateOrder(quantity: 4, times: 1)
simulateOrder(quantity: 4, times: 2)
