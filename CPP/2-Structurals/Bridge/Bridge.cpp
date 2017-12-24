#include <iostream>
#include <string>

// Implemented interface.
class WidgetAbstractInterface
{
    public:
        virtual ~WidgetAbstractInterface() {}
        virtual void createWidget() = 0;
};

// Interface for internal implementation that Bridge uses.
class ImplementationInterface
{
    public:
        virtual ~ImplementationInterface() {}
        virtual void setupWidget() = 0;
};

// The Bridge
class Bridge : public WidgetAbstractInterface
{
    protected:
        ImplementationInterface *_implementation;

    public:
        Bridge(ImplementationInterface *implementation)
        {
            _implementation = implementation;
        }
};

// Different special cases of the interface.
class Button : public Bridge
{
    public:
        Button(ImplementationInterface *implementation)
          : Bridge(implementation)
        {}

        void createWidget()
        {
            std::cout << "Button on ";
            _implementation->setupWidget();
        }
};

class TextField : public Bridge
{
    public:
        TextField(ImplementationInterface *implementation)
          : Bridge(implementation)
        {}

        void createWidget()
        {
            std::cout << "TextField on ";
            _implementation->setupWidget();
        }
};

// Different background implementations
class Windows : public ImplementationInterface
{
    public:
        void setupWidget()
        {
            std::cout << "Windows..." << std::endl;
        }
};

class Linux : public ImplementationInterface
{
    public:
        void setupWidget()
        {
            std::cout << "Linux..." << std::endl;
        }
};

int main()
{
    WidgetAbstractInterface *widget = 0;
    ImplementationInterface *osWindows = new Windows;
    ImplementationInterface *osLinux = new Linux;

    // First case
    widget = new Button(osWindows);
    widget->createWidget();
    // ... do something
    delete widget;

    widget = new Button(osLinux);
    widget->createWidget();
    // ... do something
    delete widget;

    // Second case
    widget = new TextField(osWindows);
    widget->createWidget();
    // ... do something
    delete widget;

    widget = new TextField(osLinux);
    widget->createWidget();
    // ... do something
    delete widget;

    delete osWindows;
    delete osLinux;

    return 0;
};

//-----------------------------------------------------------
/*
Output:

Button on Windows...
Button on Linux...
TextField on Windows...
TextField on Linux...

*/
