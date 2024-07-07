import Foundation

// MARK: - ObjectData

class ObjectData {
    private var value: Int
    
    init(_ v: Int) {
        self.value = v
    }
    
    func getValue() -> Int {
        return value
    }
    
    func setValue(_ v: Int) {
        value = v
    }
}

// MARK: - Strategy Protocol

protocol Strategy {
    var data: ObjectData { get }
    func serialize()
}

// MARK: - Concrete Strategies

class OnDiskStrategy: Strategy {
    let data: ObjectData
    
    init(_ d: ObjectData) {
        self.data = d
    }
    
    func serialize() {
        print("Serialize data '\(data.getValue())' on local disk.")
    }
}

class OnCloudStrategy: Strategy {
    let data: ObjectData
    
    init(_ d: ObjectData) {
        self.data = d
    }
    
    func serialize() {
        print("Serialize data '\(data.getValue())' on cloud.")
    }
}

// MARK: - Serializer

class Serializer {
    private var strategy: Strategy?
    
    func setStrategy(_ s: Strategy) {
        strategy = s
    }
    
    func save() {
        strategy?.serialize()
    }
}

// MARK: - Client Code

// We have our model that has to be saved
let obj = ObjectData(42)

// Save on disk strategy
let disk = OnDiskStrategy(obj)

let serializer = Serializer()
serializer.setStrategy(disk)
serializer.save()

// Now we want to backup our data on cloud
// so we build a cloud strategy...
let cloud = OnCloudStrategy(obj)
serializer.setStrategy(cloud)
// ... and apply it.
serializer.save()

/**
 Serialize data '42' on local disk.
 Serialize data '42' on cloud.
 */
