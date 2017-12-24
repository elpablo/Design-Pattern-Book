/* Abstract base class declared by framework */
class Color
{
public:
    virtual ~Color() {}
    virtual void ValidateSpace(double components[3]) = 0;
};

/* Framework declaration */
class ColorFactory
{
public:
    virtual ~ColorFactory() {}
    /* The client will call this "entry point" of the framework */
    Color *GetColor(double components[3])
    {
        /* Framework calls the "hook" reserved for client customization */
        Color *_color = MakeColor();
        _color->ValidateSpace(components);
        return _color;
    }

protected:
    /* Framework declares a "hook" for the client to customize */
    virtual Color *MakeColor() = 0;
};


/* Concrete derived class defined by client */
class RGBColor: public Color
{
    double _r;
    double _g;
    double _b;

public:
    void ValidateSpace(double components[3])
    {
        _r = components[0];
        _g = components[1];
        _b = components[2];
    }

    void rgbOperation()
    {
        // do something on RGB
    }
};

class HSVColor: public Color
{
    double _h;
    double _s;
    double _v;

public:
    void ValidateSpace(double components[3])
    {
        _h = components[0];
        _s = components[1];
        _v = components[2];
    }

    void hsvOperation()
    {
        // do something on HSV
    }
};

/* Customization of framework defined by client */
class ColorFactoryRGB: public ColorFactory
{
protected:
    /* Client defines Framework's "hole" */
    Color *MakeColor()
    {
        RGBColor *color = new RGBColor();
        color->rgbOperation();
        return color;
    }
};

class ColorFactoryHSV: public ColorFactory
{
protected:
    /* Client defines Framework's "hole" */
    Color *MakeColor()
    {
        HSVColor *color = new HSVColor();
        color->hsvOperation();
        return color;
    }
};


int main()
{
    /* Client's customization of the Framework */
    ColorFactory *factory = new ColorFactoryRGB(); // or ColorFactoryHSV()

    double comp[3] = {0.3, 0.1, 0.0};
    Color *color = factory->GetColor(comp);

    // ...

    delete factory;

    return 0;
}
