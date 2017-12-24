#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>

class Base
{
    Base *_next; // "_next" pointer in the base class

public:
    Base()
    {
        _next = 0;
    }

    void setNext(Base *n)
    {
        _next = n;
    }

    void add(Base *n)
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

class Handler1: public Base
{
public:
    /*virtual*/ void handle(int i)
    {
        if (rand() % 3)
        {
            // Don't handle requests 3 times out of 4
            std::cout << "H1 passed " << i << "  ";
            Base::handle(i); // Delegate to the base class
        }
        else
        {
            std::cout << "H1 handled " << i << "  ";
        }
    }
};

class Handler2: public Base
{
public:
    /*virtual*/ void handle(int i)
    {
        if (rand() % 3)
        {
            std::cout << "H2 passed " << i << "  ";
            Base::handle(i);
        }
        else
        {
            std::cout << "H2 handled " << i << "  ";
        }
    }
};

class Handler3: public Base
{
public:
    /*virtual*/ void handle(int i)
    {
        if (rand() % 3)
        {
            std::cout << "H3 passed " << i << "  ";
            Base::handle(i);
        }
        else
        {
            std::cout << "H3 handled " << i << "  ";
        }
    }
};

int main()
{
    srand(time(0));
    Handler1 mainUI;
    Handler2 textField;
    Handler3 textArea;

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

H1 passed 1  H2 passed 1  H3 handled 1
H1 passed 2  H2 handled 2
H1 passed 3  H2 passed 3  H3 handled 3
H1 handled 4
H1 passed 5  H2 passed 5  H3 passed 5  H1 handled 5
H1 handled 6
H1 handled 7
H1 passed 8  H2 handled 8
H1 passed 9  H2 handled 9

*/
