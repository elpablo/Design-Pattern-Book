#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>

class EventHandler
{
    EventHandler *_next; // "_next" pointer in the base class

public:
    EventHandler()
    {
        _next = 0;
    }

    void setNext(EventHandler *n)
    {
        _next = n;
    }

    void add(EventHandler *n)
    {
        if (_next)
        {
            _next->add(n);
        }
        else
        {
            _next = n;
        }
    }

    // The "chain" method in the base class
    // always delegates to the _next obj
    virtual void handle(int i)
    {
        _next->handle(i);
    }
};

class MouseEventHandler: public EventHandler
{
public:
    /*virtual*/ void handle(int i)
    {
        if (rand() % 3)
        {
            // Don't handle requests 3 times out of 4
            std::cout << "MouseEvent passed " << i << "  ";
            EventHandler::handle(i); // Delegate to the base class
        }
        else
        {
            std::cout << "MouseEvent handled " << i << "  ";
        }
    }
};

class KeyEventHandler: public EventHandler
{
public:
    /*virtual*/ void handle(int i)
    {
        if (rand() % 3)
        {
            std::cout << "KeyEvent passed " << i << "  ";
            EventHandler::handle(i);
        }
        else
        {
            std::cout << "KeyEvent handled " << i << "  ";
        }
    }
};

class InteractionEventHandler: public EventHandler
{
public:
    /*virtual*/ void handle(int i)
    {
        if (rand() % 3)
        {
            std::cout << "InteractionEvent passed " << i << "  ";
            EventHandler::handle(i);
        }
        else
        {
            std::cout << "InteractionEvent handled " << i << "  ";
        }
    }
};

int main()
{
    srand(time(0));
    MouseEventHandler mainUI;
    KeyEventHandler textField;
    InteractionEventHandler textArea;

    mainUI.add(&textField);
    mainUI.add(&textArea);
    textArea.setNext(&mainUI);

    for (int i = 1; i < 10; ++i)
    {
        mainUI.handle(i);
        std::cout << std::endl;
    }

    return 0;
}



//-----------------------------------------------------------
/*
Output:

MouseEvent passed 1  KeyEvent passed 1  InteractionEvent handled 1
MouseEvent passed 2  KeyEvent handled 2
MouseEvent passed 3  KeyEvent passed 3  InteractionEvent handled 3
MouseEvent handled 4
MouseEvent passed 5  KeyEvent passed 5  InteractionEvent passed 5  MouseEvent handled 5
MouseEvent handled 6
MouseEvent handled 7
MouseEvent passed 8  KeyEvent handled 8
MouseEvent passed 9  KeyEvent handled 9

*/
