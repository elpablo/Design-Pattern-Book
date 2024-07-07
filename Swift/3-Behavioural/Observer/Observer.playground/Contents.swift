import Foundation

// MARK: - Model (Subject)

class Model {
    private var observers: [Observer] = []
    private var value: Int = 0
    
    func attach(_ observer: Observer) {
        observers.append(observer)
    }
    
    func setValue(_ val: Int) {
        value = val
        notify()
    }
    
    func getValue() -> Int {
        return value
    }
    
    private func notify() {
        for observer in observers {
            observer.update()
        }
    }
}

// MARK: - Observer Protocol

protocol Observer: AnyObject {
    func update()
}

// MARK: - Abstract Observer

class AbstractObserver: Observer {
    weak var model: Model?
    let divisor: Int
    
    init(model: Model, divisor: Int) {
        self.model = model
        self.divisor = divisor
        model.attach(self)
    }
    
    func update() {
        fatalError("This method must be overridden")
    }
}

// MARK: - Concrete Observers

class DivObserver: AbstractObserver {
    override func update() {
        guard let v = model?.getValue() else { return }
        print("\(v) div \(divisor) is \(v / divisor)")
    }
}

class ModObserver: AbstractObserver {
    override func update() {
        guard let v = model?.getValue() else { return }
        print("\(v) mod \(divisor) is \(v % divisor)")
    }
}

// MARK: - Client Code

let model = Model()

// Client configures the number and type of Observers
let divObs1 = DivObserver(model: model, divisor: 4)
let divObs2 = DivObserver(model: model, divisor: 3)
let modObs3 = ModObserver(model: model, divisor: 3)

// Change the model's value to trigger the notification for the observers
model.setValue(14)

/**
 14 div 4 is 3
 14 div 3 is 4
 14 mod 3 is 2
 */
