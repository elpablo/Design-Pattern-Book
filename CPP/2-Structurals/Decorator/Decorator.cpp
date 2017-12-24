#include <iostream>

// lowest common denominator
class Widget
{
public:
    virtual ~Widget() {}
    virtual void draw() = 0;
};

class TextField: public Widget
{
    // "Core" class & "is a"
    int _width;
    int _height;

public:
    TextField(int w, int h)
    {
        _width = w;
        _height = h;
    }

    /*virtual*/ void draw()
    {
        std::cout << "TextField: " << _width << ", " << _height << std::endl;
    }
};

// 2nd level base class
// The Inheritance from the Widget
// base class gives the "is a" relationship
class Decorator: public Widget
{
    Widget *_wid; // "has a" relationship

public:
    Decorator(Widget *w)
    {
        _wid = w;
    }

    /*virtual*/ void draw()
    {
        _wid->draw(); // Delegation
    }
};

class BorderDecorator: public Decorator
{
public:
    // Optional embellishment
    BorderDecorator(Widget *w): Decorator(w){}

    /*virtual*/ void draw()
    {
        // Delegate to base class and add extra stuff
        Decorator::draw();
        std::cout << "   BorderDecorator" << std::endl;
    }
};

class ScrollDecorator: public Decorator
{
public:
    // Optional embellishment
    ScrollDecorator(Widget *w): Decorator(w){}

    /*virtual*/ void draw()
    {
        // Delegate to base class and add extra stuff
        Decorator::draw();
        std::cout << "   ScrollDecorator" << std::endl;
    }
};

int main()
{
    // Client has the responsibility to compose desired configurations
    Widget *aWidget = new BorderDecorator(
                        new BorderDecorator(
                            new ScrollDecorator(
                                new TextField(80, 24))));
    aWidget->draw();
    // ...
    delete aWidget;

    return 0;
}

//-----------------------------------------------------------
/*
Output:

TextField: 80, 24
   ScrollDecorator
   BorderDecorator
   BorderDecorator

*/
