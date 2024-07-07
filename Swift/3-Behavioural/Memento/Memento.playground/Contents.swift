import Foundation

class Memento {
    private let state: Int
    
    init(_ value: Int) {
        self.state = value
    }
    
    fileprivate func getState() -> Int {
        return state
    }
}

class Wallet {
    private var value: Int
    
    init(_ value: Int) {
        self.value = value
    }
    
    func deposit() {
        value *= 2
    }
    
    func withdraw() {
        value /= 2
    }
    
    func getValue() -> Int {
        return value
    }
    
    func createMemento() -> Memento {
        return Memento(value)
    }
    
    func assignMemento(_ memento: Memento) {
        value = memento.getState()
    }
}

class Command {
    typealias Action = () -> Void
    
    private let receiver: Wallet
    private let action: Action
    
    private static var commandList: [Command] = []
    private static var mementoList: [Memento] = []
    private static var numCommands = 0
    private static var highWater = 0
    
    init(_ receiver: Wallet, _ action: @escaping Action) {
        self.receiver = receiver
        self.action = action
    }
    
    func execute() {
        Command.mementoList.append(receiver.createMemento())
        Command.commandList.append(self)
        if Command.numCommands > Command.highWater {
            Command.highWater = Command.numCommands
        }
        Command.numCommands += 1
        action()
    }
    
    static func undo() {
        guard numCommands > 0 else {
            print("*** Attempt to run off the end!! ***")
            return
        }
        numCommands -= 1
        commandList[numCommands].receiver.assignMemento(mementoList[numCommands])
    }
    
    static func redo() {
        guard numCommands <= highWater else {
            print("*** Attempt to run off the end!! ***")
            return
        }
        commandList[numCommands].action()
        numCommands += 1
    }
}

// Client code
print("Amount: ", terminator: "")
if let input = readLine(), let initialAmount = Int(input) {
    let wallet = Wallet(initialAmount)
    
    let depositCommand = Command(wallet) { wallet.deposit() }
    let withdrawCommand = Command(wallet) { wallet.withdraw() }
    
    while true {
        print("Exit[0], Deposit[1], Withdraw[2], Undo[3], Redo[4]: ", terminator: "")
        guard let input = readLine(), let choice = Int(input) else { continue }
        
        if choice == 0 { break }
        
        switch choice {
        case 1: depositCommand.execute()
        case 2: withdrawCommand.execute()
        case 3: Command.undo()
        case 4: Command.redo()
        default: continue
        }
        
        print("   \(wallet.getValue())")
    }
}
