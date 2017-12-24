#include <iostream>
#include <math.h>

class CircleData
{
    // Private Class Data variables cannot be modified
    // by anyone externally to the CircleData class and their
    // structure is hidden to the client code that use the
    // Circle class
    double radius;
    double origin[2];

public:
    CircleData(double radius, double origin_x, double origin_y)
    {
        this->radius = radius;
        this->origin[0] = origin_x;
        this->origin[1] = origin_y;
    }

    double Radius()
    {
        return this->radius;
    }

    double OriginX()
    {
        return this->origin[0];
    }

    double OriginY()
    {
        return this->origin[1];
    }
};


class Circle
{
    CircleData *circleData;

public:
    Circle(double r, double x, double y)
    {
        this->circleData = new CircleData(r, x, y);
    }

    double Circumference()
    {
        return 2.0 * this->circleData->Radius() * M_PI;
    }

    double Diameter()
    {
        return this->circleData->Radius() * 2.0;
    }

    void Draw()
    {
        //...
    }
};

int main()
{
    Circle c(5, 0, 0);

    std::cout << "Circumference: " << c.Circumference() << std::endl;
    std::cout << "Diameter: " << c.Diameter() << std::endl;

    return 0;
}

//-----------------------------------------------------------
/*
Output:

Circumference: 31.4159
Diameter: 10

*/
