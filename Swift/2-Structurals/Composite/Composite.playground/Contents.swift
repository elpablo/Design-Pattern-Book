import Foundation

// "interface" Filter protocol
protocol FilterInterface {
    func applyFilter()
}

// Single object class
class Filter: FilterInterface {
    private let value: Int
    
    init(_ value: Int) {
        self.value = value
    }
    
    func applyFilter() {
        print(value, terminator: " ")
    }
}

// Group objects class
class FilterGroup: FilterInterface {
    private var children: [FilterInterface] = []
    
    func add(_ filter: FilterInterface) {
        children.append(filter)
    }
    
    func applyFilter() {
        children.forEach { $0.applyFilter() }
    }
}

// Usage
// Build a single filter
let single = Filter(42)

// Setup a group of filters
let group = FilterGroup()
for i in 0..<4 {
    group.add(Filter(i))
}

// Build a group of group of filters
let megaGroup = FilterGroup()
let group2 = FilterGroup()
for j in 5..<10 {
    group2.add(Filter(j))
}
megaGroup.add(group2)

// Apply the single filter
print("Single filter:")
single.applyFilter()
print("\n")

// Apply the filter's group
print("Filter group:")
group.applyFilter()
print("\n")

// Apply the filter's mega group
print("Mega group:")
megaGroup.applyFilter()
print("\n")

/**
 Single filter:
 42

 Filter group:
 0 1 2 3

 Mega group:
 5 6 7 8 9
 */
