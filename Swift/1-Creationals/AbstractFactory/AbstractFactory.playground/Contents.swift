
import UIKit

protocol Drawable {
    func draw(_ rect: CGRect)
}

class UIButton: Drawable {
    func draw(_ rect: CGRect) {
        print("Draw a button in iOS")
    }
}

class NSButton: Drawable {
    func draw(_ rect: CGRect) {
        print("Draw a button in macOS")
    }
}

protocol WidgetFactory {
    func createButton() -> Drawable
}

class iOSFactory: WidgetFactory {
    func createButton() -> Drawable {
        return UIButton()
    }
}

class macOSFactory: WidgetFactory {
    func createButton() -> Drawable {
        return NSButton()
    }
}

enum WidgetFactoryHelper {
    case IOS, MACOS
    
    func getFactory() -> WidgetFactory {
        switch self {
        case .IOS:
            return iOSFactory()
        case .MACOS:
            return macOSFactory()
        }
    }
}

/* Usage */

let factory: WidgetFactoryHelper = .IOS
let button:Drawable = factory.getFactory().createButton()
button.draw(CGRect(x: 0, y: 0, width: 100, height: 100))

/**
 Output:
 
 Draw a button in iOS

 */
