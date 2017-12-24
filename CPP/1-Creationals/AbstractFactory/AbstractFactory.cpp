#include <iostream>

// This is the interface class for the Button
class IButton
{
public:
    virtual ~IButton() {}
    virtual void Paint() = 0;
};

// Windows button implementation
class WinButton : public IButton
{
public:
    /*virtual*/ void Paint()
    {
        //Render a button in a Windows style
    }
};

// Mac button implementation
class OSXButton : public IButton
{
public:
    /*virtual*/ void Paint()
    {
        //Render a button in a Mac OS X style
    }
};

// This is the interface class for the Factory that will build the Button
class IGUIFactory
{
public:
    virtual ~IGUIFactory() {}
    virtual IButton *CreateButton() = 0;
};

// Concrete Factory implementation for Windows
class WinFactory : public IGUIFactory
{
public:
    /*virtual*/ IButton *CreateButton()
    {
        return new WinButton();
    }
};

// Concrete Factory implementation for Mac
class OSXFactory : public IGUIFactory
{
public:
    /*virtual*/ IButton *CreateButton()
    {
        return new OSXButton();
    }
};

// In your software choose which is the appearance you
// want to give to your widgets by instantiating the correspoding concrete factory
enum {
    WINDOWS = 0,
    MACOSX
};
static int appearance = MACOSX;

int main()
{
    IGUIFactory *factory;
    switch (appearance)
    {
        case WINDOWS:
            factory = new WinFactory();
            break;
        case MACOSX:
            factory = new OSXFactory();
            break;
        default:
            std::cout << "No factory available for this case" << std::endl;
    }

    // From now ahead, you can use the factory to create the button and it
    // will return the instance for the coresponding Operative System
    IButton *button = factory->CreateButton();
    button->Paint();

    // ...

    delete factory;

    return 0;
}
