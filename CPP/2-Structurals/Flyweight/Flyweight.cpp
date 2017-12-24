#include <iostream>
#include <string>
#include <map>

// The 'Flyweight' abstract class
class Character
{
public:
    virtual ~Character() {}
    virtual void display(int pointSize) = 0;

protected:
    char _symbol;
    int _width;
    int _height;
    int _ascent;
    int _descent;
    int _pointSize;
};

// A 'ConcreteFlyweight' class
class CharacterA : public Character
{
public:
    CharacterA()
    {
        // Shared part between all the
        // characters 'A' of a string
        _symbol    = 'A';
        _width     = 120;
        _height    = 100;
        _ascent    = 70;
        _descent   = 0;

        // initialise the not sharable content
        _pointSize = 0;
    }
    void display(int pointSize)
    {
        _pointSize = pointSize;
        std::cout << _symbol
                  << " (pointsize "
                  << _pointSize
                  << " )"
                  << std::endl;
    }
};

// A 'ConcreteFlyweight' class
class CharacterB : public Character
{
public:
    CharacterB()
    {
        // Shared part between all the
        // characters 'B' of a string
        _symbol    = 'B';
        _width     = 140;
        _height    = 100;
        _ascent    = 72;
        _descent   = 0;

        // initialise the not sharable content
        _pointSize = 0;
    }
    void display(int pointSize)
    {
        _pointSize = pointSize;
        std::cout << _symbol
                  << " (pointsize "
                  << _pointSize
                  << " )"
                  << std::endl;
    }
};

// C, D, E,...

// A 'ConcreteFlyweight' class
class CharacterZ : public Character
{
public:
    CharacterZ()
    {
        // Shared part between all the
        // characters 'Z' of a string
        _symbol    = 'Z';
        _width     = 100;
        _height    = 100;
        _ascent    = 68;
        _descent   = 0;

        // initialise the not sharable content
        _pointSize = 0;
    }
    void display(int pointSize)
    {
        _pointSize = pointSize;
        std::cout << _symbol
                  << " (pointsize "
                  << _pointSize
                  << " )"
                  << std::endl;
    }
};

// The 'FlyweightFactory' class
class CharacterFactory
{
public:
    virtual ~CharacterFactory()
    {
        while(!_characters.empty())
        {
            std::map<char, Character*>::iterator it = _characters.begin();
            delete it->second;
            _characters.erase(it);
        }
    }

    Character *getCharacter(char key)
    {
        Character *character = NULL;
        if(_characters.find(key) != _characters.end())
        {
            character = _characters[key];
        }
        else
        {
            switch(key)
            {
                case 'A':
                    character = new CharacterA();
                    break;
                case 'B':
                    character = new CharacterB();
                    break;
                //...
                case 'Z':
                    character = new CharacterZ();
                    break;
                default:
                    std::cout << "Not Implemented" << std::endl;
                    throw("Not Implemented");
            }
            _characters[key] = character;
        }
        return character;
    }
private:
    std::map<char, Character*> _characters;
};


// Client code
int main()
{
    std::string document = "AAZZBBZB";
    const char *chars = document.c_str();

    CharacterFactory* factory = new CharacterFactory;

    // extrinsic state
    int pointSize = 10;

    // For each character use a flyweight object
    for(size_t i = 0; i < document.length(); ++i)
    {
        ++pointSize;
        Character *character = factory->getCharacter(chars[i]);
        character->display(pointSize);
    }

    // Clean memory
    delete factory;

    return 0;
}

/**********************************************************************
 Output:
 A (pointsize 11)
 A (pointsize 12)
 Z (pointsize 13)
 Z (pointsize 14)
 B (pointsize 15)
 B (pointsize 16)
 Z (pointsize 17)
 B (pointsize 18)
**********************************************************************/
