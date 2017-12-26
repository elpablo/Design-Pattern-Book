#include <iostream>

// Base class with lowest common APIs
class Widget
{
public:
    virtual ~Widget() {}
    virtual void draw() = 0;
};

// Button is the core class to draw the widget
class Button: public Widget
{
    int _width;
    int _height;

public:
    Button(int w, int h)
    {
        _width = w;
        _height = h;
    }

    /*virtual*/ void draw()
    {
        std::cout << "Button: " << _width << ", " << _height << std::endl;
    }
};

// The inheritance from the Widget
// base class gives the "is a" relationship
class Decorator: public Widget
{
    Widget *_widget; // "has a" relationship

public:
    Decorator(Widget *f)
    {
        _widget = f;
    }

    /*virtual*/ void draw()
    {
        _widget->draw(); // Delegate execution
    }
};

class BorderDecorator: public Decorator
{
public:
    // Optional decoration
    BorderDecorator(Widget *w): Decorator(w){}

    /*virtual*/ void draw()
    {
        // Delegate to base class and add extra widget's decoration
        Decorator::draw();
        std::cout << "   BorderDecorator" << std::endl;
    }
};

class ButtonImageDecorator: public Decorator
{
public:
    // Optional decoration
    ButtonImageDecorator(Widget *w): Decorator(w) {}

    /*virtual*/ void draw()
    {
        // Delegate to base class and add extra widget's decoration
        Decorator::draw();
        std::cout << "   ButtonImageDecorator" << std::endl;
    }
};

int main()
{
    // Client has the responsibility to compose desired configurations
    Widget *btn = new BorderDecorator(
                      new ButtonImageDecorator(
                          new Button(44, 44)));
    btn->draw();
    // ...
    delete btn;

    return 0;
}

//-----------------------------------------------------------
/*
Output:

Button: 44, 44
ButtonImageDecorator
BorderDecorator

*/
