import Foundation

// Container class
class Container {
    private var items: [Int] = []
    
    func push(_ item: Int) {
        items.append(item)
    }
    
    func pop() -> Int? {
        return items.popLast()
    }
    
    var isEmpty: Bool {
        return items.isEmpty
    }
    
    func createIterator() -> ContainerIterator {
        return ContainerIterator(container: self)
    }
    
    // Method to access items, visible only to ContainerIterator
    fileprivate func getItem(at index: Int) -> Int? {
        guard index >= 0 && index < items.count else { return nil }
        return items[index]
    }
    
    fileprivate var count: Int {
        return items.count
    }
}

// Iterator protocol
protocol Iterator {
    associatedtype Element
    func next() -> Element?
    func hasNext() -> Bool
}

// ContainerIterator class
class ContainerIterator: Iterator {
    typealias Element = Int
    
    private let container: Container
    private var index: Int = 0
    
    init(container: Container) {
        self.container = container
    }
    
    func next() -> Int? {
        guard hasNext() else { return nil }
        defer { index += 1 }
        return container.getItem(at: index)
    }
    
    func hasNext() -> Bool {
        return index < container.count
    }
}

// Client code
let container = Container()
for i in 1...4 {
    container.push(i)
}

let iterator = container.createIterator()

while iterator.hasNext() {
    if let item = iterator.next() {
        print("Item: \(item)")
    }
}

/**
 Item: 1
 Item: 2
 Item: 3
 Item: 4
 */
