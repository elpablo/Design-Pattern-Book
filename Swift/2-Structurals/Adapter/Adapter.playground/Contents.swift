import Foundation

// Adaptee (old code) protocol
protocol ColorInterface {
    func red() -> Double
    func green() -> Double
    func blue() -> Double
}

// Adaptee (concrete old style object)
class RGBColor: ColorInterface {
    func red() -> Double { return 1 }
    func green() -> Double { return 0.87 }
    func blue() -> Double { return 0 }
}

// Target protocol
protocol RGBAColor {
    func alpha() -> Double
    func red() -> Double
    func green() -> Double
    func blue() -> Double
}

// The Adapter
class Adapter: RGBAColor {
    private var oldStyleColor: ColorInterface?
    
    func setColor(_ color: ColorInterface) {
        oldStyleColor = color
    }
    
    func alpha() -> Double { return 1 }
    func red() -> Double { return oldStyleColor?.red() ?? 0 }
    func green() -> Double { return oldStyleColor?.green() ?? 0 }
    func blue() -> Double { return oldStyleColor?.blue() ?? 0 }
}

// Client code
class ColorSpaceFilter {
    private var color: RGBAColor?
    
    func setColor(_ color: RGBAColor) {
        self.color = color
    }
    
    func apply() {
        guard let color = color else {
            print("No color set")
            return
        }
        
        // Use the new RGBA color style
        print("Applying color filtering...")
        print("red: \(color.red())")
        print("green: \(color.green())")
        print("blue: \(color.blue())")
        print("alpha: \(color.alpha())")
    }
}

// Usage
let oldStyleColor = RGBColor()
let adapter = Adapter()
adapter.setColor(oldStyleColor)

let filter = ColorSpaceFilter()
// Plugging in
filter.setColor(adapter)

// Apply new style filter
filter.apply()

/**
 Applying color filtering...
 red: 1.0
 green: 0.87
 blue: 0.0
 alpha: 1.0
 */
