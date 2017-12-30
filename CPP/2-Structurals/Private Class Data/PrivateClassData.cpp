#include <iostream>
#include <math.h>

class ModelData
{
    // Private Class Data variables cannot be modified
    // by anyone externally to the ModelData class and their
    // structure is hidden to the client code that use the
    // Circle class
    double _radius;
    double _origin[2];

public:
    ModelData(double radius, double origin_x, double origin_y)
    {
        this->_radius = radius;
        this->_origin[0] = origin_x;
        this->_origin[1] = origin_y;
    }

    double radius()
    {
        return this->_radius;
    }

    double originX()
    {
        return this->_origin[0];
    }

    double originY()
    {
        return this->_origin[1];
    }
};


class Circle
{
    ModelData *_data;

public:
    Circle(double r, double x, double y)
    {
        this->_data = new ModelData(r, x, y);
    }

    double circumference()
    {
        return 2.0 * this->_data->radius() * M_PI;
    }

    double diameter()
    {
        return this->_data->radius() * 2.0;
    }

    void draw()
    {
        //...
    }
};

int main()
{
    Circle c(5, 0, 0);

    std::cout << "circumference: " << c.circumference() << std::endl;
    std::cout << "diameter: " << c.diameter() << std::endl;

    return 0;
}

//-----------------------------------------------------------
/*
Output:

circumference: 31.4159
diameter: 10

*/
