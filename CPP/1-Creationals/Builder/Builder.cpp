#include <string>

class Image;


// Builder
class ImageBuilder
{
    std::string _name;
    int size[2];

public:
    // Assign the file name of the image to read
    ImageBuilder *setName(std::string name)
    {
        this->_name = name;
        return this;
    }
    // Assign the size of the image we want as output
    ImageBuilder *setSize(int w, int h)
    {
        this->size[0] = w;
        this->size[1] = h;
        return this;
    }
    // When we have assigned all the information we can call the build method
    Image *build()
    {
        // Use the information to create
        // the Image to pass to the caller
        return NULL;
    }
};

class ImageViewer
{
    Image *_image;

public:
    void setImage(Image *img)
    {
        this->_image = img;
    }
};

int main()
{
    ImageBuilder builder;
    ImageViewer viewer;

    viewer.setImage((&builder)->setName("MyImage.jpg")
                              ->setSize(100, 100)
                              ->build());

    return 0;
}
