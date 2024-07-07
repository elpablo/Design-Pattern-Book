import Foundation

// Protocol (equivalent to abstract class in C++)
protocol Item {
    func doSomething()
}

// Concrete implementation
class FileItem: Item {
    func doSomething() {
        print("calculate checksum...")
    }
}

// Null Object implementation
class NullItem: Item {
    func doSomething() {
        // Do nothing
    }
}

// Client code
let items: [Item] = [FileItem(), NullItem()]

print("Item 0 (Active): ", terminator: "")
items[0].doSomething()

print("Item 1 (Null): ", terminator: "")
items[1].doSomething()

print()

/**
 Item 0 (Active): calculate checksum...
 Item 1 (Null):
 */
