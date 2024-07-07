import Foundation

// Prototype base protocol
protocol Filter {
    func clone() -> Filter
    func applyFilter()
}

// Concrete Prototype classes
class GaussianBlur: Filter {
    func clone() -> Filter {
        return GaussianBlur()
    }
    
    func applyFilter() {
        print("GaussianBlur: applying filter...")
    }
}

class Pixelate: Filter {
    func clone() -> Filter {
        return Pixelate()
    }
    
    func applyFilter() {
        print("Pixelate: applying filter...")
    }
}

class Threshold: Filter {
    func clone() -> Filter {
        return Threshold()
    }
    
    func applyFilter() {
        print("Threshold: applying filter...")
    }
}

// Factory class
class Factory {
    private static let prototypes: [Filter] = [
        GaussianBlur(),
        Pixelate(),
        Threshold()
    ]
    
    static func makeFilter(filterIndex: Int) -> Filter {
        return prototypes[filterIndex].clone()
    }
}

// Use the prototype pattern
var filters: [Filter] = []

// Create some filters
// 0 => GaussianBlur, 1 => Pixelate, 2 => Threshold
filters.append(Factory.makeFilter(filterIndex: 0))
filters.append(Factory.makeFilter(filterIndex: 2))
filters.append(Factory.makeFilter(filterIndex: 1))

// Use all the created filters
for filter in filters {
    filter.applyFilter()
}

print("\nMemory addresses of filters:")
for (index, filter) in filters.enumerated() {
    print("Filter \(index): \(Unmanaged.passUnretained(filter as AnyObject).toOpaque())")
}

/**
 GaussianBlur: applying filter...
 Threshold: applying filter...
 Pixelate: applying filter...

 Memory addresses of filters:
 Filter 0: 0x600003750120
 Filter 1: 0x6000037501e0
 Filter 2: 0x600003750180
 */
