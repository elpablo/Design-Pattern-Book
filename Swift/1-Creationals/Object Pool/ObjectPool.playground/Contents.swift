import Foundation

class ImageResource {
    private var url: String = ""
    
    func setImageURL(_ url: String) {
        self.url = url
    }
    
    func getImageURL() -> String {
        return url
    }
    
    func reset() {
        url = ""
    }
}

class ObjectPool {
    private var images: [ImageResource] = []
    
    private init() {}
    
    static let shared = ObjectPool()
    
    func getImageResource() -> ImageResource {
        if images.isEmpty {
            print("Creating new.")
            return ImageResource()
        } else {
            print("Reusing existing.")
            return images.removeFirst()
        }
    }
    
    func returnImageResource(_ object: ImageResource) {
        object.reset()
        images.append(object)
    }
    
    func freePool() {
        images.removeAll()
    }
}

// Usage example
let pool = ObjectPool.shared

print("Getting first resource:")
let one = pool.getImageResource()
one.setImageURL("https://www.dataresources.com/server_entry_point.php")
print("one = \(one.getImageURL()) [\(Unmanaged.passUnretained(one).toOpaque())]")

print("\nGetting second resource:")
let two = pool.getImageResource()
two.setImageURL("https://www.another-dataresources.com/another_server_entry_point.php")
print("two = \(two.getImageURL()) [\(Unmanaged.passUnretained(two).toOpaque())]")

print("\nReturning resources to the pool")
pool.returnImageResource(one)
pool.returnImageResource(two)

print("\nGetting resources again:")
let oneAgain = pool.getImageResource()
print("one = \(oneAgain.getImageURL()) [\(Unmanaged.passUnretained(oneAgain).toOpaque())]")

let twoAgain = pool.getImageResource()
print("two = \(twoAgain.getImageURL()) [\(Unmanaged.passUnretained(twoAgain).toOpaque())]")

pool.freePool()

/**
 Getting first resource:
 Creating new.
 one = https://www.dataresources.com/server_entry_point.php [0x600003138120]

 Getting second resource:
 Creating new.
 two = https://www.another-dataresources.com/another_server_entry_point.php [0x600003138180]

 Returning resources to the pool

 Getting resources again:
 Reusing existing.
 one =  [0x600003138120]
 Reusing existing.
 two =  [0x600003138180]
 */
