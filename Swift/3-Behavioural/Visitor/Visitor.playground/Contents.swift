import Foundation

// MARK: - PageModel

protocol PageBase {
    func accept(visitor: Visitor)
}

class Page: PageBase {
    func accept(visitor: Visitor) {
        visitor.visit(page: self)
    }
    
    func text() -> String {
        return "Page Text"
    }
}

// MARK: - Visitor

protocol Visitor {
    func visit(page: Page)
}

class UppercaseVisitor: Visitor {
    private var str: String = ""
    
    func visit(page: Page) {
        self.str = page.text().uppercased()
    }
    
    func text() -> String {
        return self.str
    }
}

class LowercaseVisitor: Visitor {
    private var str: String = ""
    
    func visit(page: Page) {
        self.str = page.text().lowercased()
    }
    
    func text() -> String {
        return self.str
    }
}

// MARK: - Main

let page = Page()

let uppercaseVisitor = UppercaseVisitor()
let lowercaseVisitor = LowercaseVisitor()

page.accept(visitor: uppercaseVisitor)
print("Visited Uppercase text: \(uppercaseVisitor.text())")

page.accept(visitor: lowercaseVisitor)
print("Visited Lowercase text: \(lowercaseVisitor.text())")

/**
 Visited Uppercase text: PAGE TEXT
 Visited Lowercase text: page text
 */
