import Foundation

class ModelData {
    // Private properties cannot be modified externally
    private let radius: Double
    private let origin: (x: Double, y: Double)
    
    init(radius: Double, originX: Double, originY: Double) {
        self.radius = radius
        self.origin = (x: originX, y: originY)
    }
    
    func getRadius() -> Double {
        return radius
    }
    
    func getOriginX() -> Double {
        return origin.x
    }
    
    func getOriginY() -> Double {
        return origin.y
    }
}

class Circle {
    private let data: ModelData
    
    init(radius: Double, x: Double, y: Double) {
        self.data = ModelData(radius: radius, originX: x, originY: y)
    }
    
    func circumference() -> Double {
        return 2.0 * data.getRadius() * Double.pi
    }
    
    func diameter() -> Double {
        return data.getRadius() * 2.0
    }
    
    func draw() {
        // Drawing implementation would go here
    }
}

// Client code
let circle = Circle(radius: 5, x: 0, y: 0)

print("Circumference: \(circle.circumference())")
print("Diameter: \(circle.diameter())")

/**
 Circumference: 31.41592653589793
 Diameter: 10.0
 */
