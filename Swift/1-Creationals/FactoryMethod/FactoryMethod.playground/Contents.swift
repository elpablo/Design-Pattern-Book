import Foundation

// Abstract base protocol declared by framework
protocol Color {
    func validateSpace(components: [Double])
}

// Framework declaration
protocol ColorFactory {
    func getColor(components: [Double]) -> Color
    func makeColor() -> Color
}

extension ColorFactory {
    func getColor(components: [Double]) -> Color {
        // Framework calls the "hook" reserved for client customization
        let color = makeColor()
        color.validateSpace(components: components)
        return color
    }
}

// Concrete classes defined by client
class RGBColor: Color {
    private var r: Double = 0
    private var g: Double = 0
    private var b: Double = 0
    
    func validateSpace(components: [Double]) {
        r = components[0]
        g = components[1]
        b = components[2]
    }
    
    func rgbOperation() {
        print("RGB Operation: R:\(r), G:\(g), B:\(b)")
    }
}

class HSVColor: Color {
    private var h: Double = 0
    private var s: Double = 0
    private var v: Double = 0
    
    func validateSpace(components: [Double]) {
        h = components[0]
        s = components[1]
        v = components[2]
    }
    
    func hsvOperation() {
        print("HSV Operation: H:\(h), S:\(s), V:\(v)")
    }
}

// Customization of framework defined by client
class ColorFactoryRGB: ColorFactory {
    func makeColor() -> Color {
        let color = RGBColor()
        color.rgbOperation()
        return color
    }
}

class ColorFactoryHSV: ColorFactory {
    func makeColor() -> Color {
        let color = HSVColor()
        color.hsvOperation()
        return color
    }
}

// Usage example
func testColorFactory(factory: ColorFactory, components: [Double]) {
    print("Testing with \(type(of: factory))")
    let color = factory.getColor(components: components)
    print("Color created: \(type(of: color))")
    print("---")
}

// Run the tests
let rgbFactory = ColorFactoryRGB()
let hsvFactory = ColorFactoryHSV()
let components = [0.3, 0.1, 0.0]

testColorFactory(factory: rgbFactory, components: components)
testColorFactory(factory: hsvFactory, components: components)
