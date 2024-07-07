import Foundation

class MySingleton {
    // Private initializer to prevent direct instantiation
    private init() {}
    
    // Static property for the single instance
    static let shared = MySingleton()
    
    func doSomething(param: Int) {
        print("Do something... \(param)")
    }
}

// Example usage of Singleton object
let s = MySingleton.shared
s.doSomething(param: 42)

// Demonstrating that we always get the same instance
let anotherReference = MySingleton.shared
print("Are both references the same instance? \(s === anotherReference)")

/**
 Do something... 42
 Are both references the same instance? true
 */
