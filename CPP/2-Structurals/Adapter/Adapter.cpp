#include <iostream>
#include <string>

// Adaptee (old code) interface
class ColorInterface
{
public:
    virtual double red() = 0;
    virtual double green() = 0;
    virtual double blue() = 0;
};

// Adaptee (concrete old style object)
class RGBColor : public ColorInterface
{
public:
    double red() { return 1; }
    double green() { return .87; }
    double blue() { return 0; }
};

/* Target interface */
class RGBAColor
{
public:
    virtual double alpha() = 0;
    virtual double red() = 0;
    virtual double green() = 0;
    virtual double blue() = 0;
};

// The Adapter
class Adapter : public RGBAColor
{
ColorInterface *_old_style_color;

public:
    void setColor(ColorInterface *color)
    {
        _old_style_color = color;
    }

    double alpha() { return 1; }
    double red() { return _old_style_color->red(); }
    double green() { return _old_style_color->green(); }
    double blue() { return _old_style_color->blue(); }
};

// Client code
class ColorSpaceFilter
{
RGBAColor *_color;

public:
    void setColor(RGBAColor *color)
    {
        _color = color;
    }

    void apply()
    {
        // Use the new RGBA color style
        std::cout << "Applying color filtering..." << std::endl;
        std::cout << "red: " << _color->red() << std::endl;
        std::cout << "green: " << _color->green() << std::endl;
        std::cout << "blue: " << _color->blue() << std::endl;
        std::cout << "alpha: " << _color->alpha() << std::endl;
    }
};


int main()
{
    RGBColor old_style_color;
    Adapter adapter;
    adapter.setColor(&old_style_color);

    ColorSpaceFilter filter;
    // Pluging in.
    filter.setColor(&adapter);

    // Apply new style filter
    filter.apply();

    return 0;
}

//-----------------------------------------------------------
/*
Output:

Applying color filtering...
red: 1
green: 0.87
blue: 0
alpha: 1

*/
