#include <iostream>

class RealImage
{
    int _id;

public:
    RealImage(int i)
    {
        _id = i;
        std::cout << "   ctor: " << _id << std::endl;
    }

    ~RealImage()
    {
        std::cout << "   dtor: " << _id << std::endl;
    }

    void draw()
    {
        std::cout << "   drawing the image " << _id << std::endl;
    }
};

// Design an "extra level of indirection" proxy class
class ImageProxy
{
    // The proxy class holds a pointer to the real class
    RealImage *_the_real_image;
    int _id;
    static int _next;

public:
    ImageProxy()
    {
        _id = _next++;
        // Initialized to null
        _the_real_image = NULL;
    }

    ~ImageProxy()
    {
        if (_the_real_image != NULL)
        {
            delete _the_real_image;
        }
    }

    void draw()
    {
        // When a request comes in, the real object is
        //    created "on first use"
        if (NULL == _the_real_image)
        {
            _the_real_image = new RealImage(_id);
        }
        // The request is always delegated
        _the_real_image->draw();
    }
};

// Initialize the proxy’s counter
int ImageProxy::_next = 1;

int main()
{
    ImageProxy images[5];

    for (int i = 0; i < 5; ++i)
    {
        images[i].draw();
    }

    return 0;
}

//-----------------------------------------------------------
/*
Output:

ctor: 1
drawing image 1
ctor: 2
drawing image 2
ctor: 3
drawing image 3
ctor: 4
drawing image 4
ctor: 5
drawing image 5
dtor: 5
dtor: 4
dtor: 3
dtor: 2
dtor: 1

*/
