import Foundation

protocol ExpressionInterpreter {
    func interpret() -> Int
}

class NumberExpression: ExpressionInterpreter {
    private let number: Int
    
    init(_ n: Int) {
        self.number = n
    }
    
    func interpret() -> Int {
        return number
    }
}

class AddExpression: ExpressionInterpreter {
    private let leftExpression: ExpressionInterpreter
    private let rightExpression: ExpressionInterpreter
    
    init(_ left: ExpressionInterpreter, _ right: ExpressionInterpreter) {
        self.leftExpression = left
        self.rightExpression = right
    }
    
    func interpret() -> Int {
        return leftExpression.interpret() + rightExpression.interpret()
    }
}

class SubtractExpression: ExpressionInterpreter {
    private let leftExpression: ExpressionInterpreter
    private let rightExpression: ExpressionInterpreter
    
    init(_ left: ExpressionInterpreter, _ right: ExpressionInterpreter) {
        self.leftExpression = left
        self.rightExpression = right
    }
    
    func interpret() -> Int {
        return leftExpression.interpret() - rightExpression.interpret()
    }
}

class TokenContext {
    private var tokenList: [String]
    
    init(_ tokenString: String) {
        self.tokenList = tokenString.components(separatedBy: " ")
    }
    
    func readToken() -> ExpressionInterpreter {
        return readNextToken()
    }
    
    private func readNextToken() -> ExpressionInterpreter {
        let token = tokenList.removeFirst()
        if let number = Int(token) {
            return NumberExpression(number)
        } else {
            return readNonTerminal()
        }
    }
    
    private func readNonTerminal() -> ExpressionInterpreter {
        let token = tokenList.removeFirst()
        let left = readNextToken()
        let right = readNextToken()
        
        switch token {
        case "+":
            return AddExpression(left, right)
        case "-":
            return SubtractExpression(left, right)
        default:
            fatalError("Unknown operator")
        }
    }
}

// Client code
let context1 = TokenContext("+ - 10 2 3")
let expression1 = context1.readToken()
print(expression1.interpret())  // (10 - 2) + 3 = 11

let context2 = TokenContext("- + 10 5 - 8 2")
let expression2 = context2.readToken()
print(expression2.interpret())  // (10 + 5) - (8 - 2) = 9

/**
 Output looks like:
 11
 9
 */
