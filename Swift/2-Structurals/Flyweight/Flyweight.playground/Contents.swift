import Foundation

// The 'Flyweight' protocol
protocol Character {
    func display(pointSize: Int)
}

// A 'ConcreteFlyweight' class
class CharacterA: Character {
    private let symbol: Character = "A"
    private let width: Int = 120
    private let height: Int = 100
    private let ascent: Int = 70
    private let descent: Int = 0
    private var pointSize: Int = 0
    
    func display(pointSize: Int) {
        self.pointSize = pointSize
        print("\(symbol) (pointsize \(pointSize))")
    }
}

// B 'ConcreteFlyweight' class
class CharacterB: Character {
    private let symbol: Character = "B"
    private let width: Int = 140
    private let height: Int = 100
    private let ascent: Int = 72
    private let descent: Int = 0
    private var pointSize: Int = 0
    
    func display(pointSize: Int) {
        self.pointSize = pointSize
        print("\(symbol) (pointsize \(pointSize))")
    }
}

// Z 'ConcreteFlyweight' class
class CharacterZ: Character {
    private let symbol: Character = "Z"
    private let width: Int = 100
    private let height: Int = 100
    private let ascent: Int = 68
    private let descent: Int = 0
    private var pointSize: Int = 0
    
    func display(pointSize: Int) {
        self.pointSize = pointSize
        print("\(symbol) (pointsize \(pointSize))")
    }
}

// The 'FlyweightFactory' class
class CharacterFactory {
    private var characters: [Character: Character] = [:]
    
    func getCharacter(_ key: Character) -> Character {
        if let character = characters[key] {
            return character
        } else {
            let character: Character
            switch key {
            case "A":
                character = CharacterA()
            case "B":
                character = CharacterB()
            case "Z":
                character = CharacterZ()
            default:
                fatalError("Not Implemented")
            }
            characters[key] = character
            return character
        }
    }
}

// Client code
let document = "AAZZBBZB"
let factory = CharacterFactory()

// extrinsic state
var pointSize = 10

// For each character use a flyweight object
for char in document {
    pointSize += 1
    let character = factory.getCharacter(char)
    character.display(pointSize: pointSize)
}

/**
 A (pointsize 11)
 A (pointsize 12)
 Z (pointsize 13)
 Z (pointsize 14)
 B (pointsize 15)
 B (pointsize 16)
 Z (pointsize 17)
 B (pointsize 18)
 */
