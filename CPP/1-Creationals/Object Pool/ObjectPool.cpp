#include <string>
#include <iostream>
#include <list>

class ImageResource
{
    std::string _url;

public:
    ImageResource() : _url("")
    {
    }

    void setImageURL(std::string url)
    {
        _url = url;
    }

    std::string getImageURL() const
    {
        return _url;
    }

    void reset()
    {
        _url = "";
    }
};

/*
Basic implementation of the ObjectPool.
Note, that this class is a singleton (see Singleton example for full implementation).
*/
class ObjectPool
{
private:
    std::list<ImageResource *> _images;

    ObjectPool() {}

public:
    /**
     * Static method for accessing class instance.
     * Part of Singleton design pattern.
     *
     * @return ObjectPool instance.
     */
    static ObjectPool &getInstance()
    {
        static ObjectPool instance;
        return instance;
    }

    /**
     * Returns instance of ImageResource.
     *
     * New ImageResource will be created if all the ImageResources
     * were used at the time of the request.
     *
     * @return ImageResource instance.
     */
    ImageResource* getImageResource()
    {
        if (_images.empty())
        {
            std::cout << "Creating new." << std::endl;
            return new ImageResource;
        }
        else
        {
            std::cout << "Reusing existing." << std::endl;
            ImageResource *img = _images.front();
            _images.pop_front();
            return img;
        }
    }

    /**
     * Return ImageResource back to the pool.
     *
     * The ImageResource must be initialized back to
     * the default settings before someone else
     * attempts to use it.
     *
     * @param object ImageResource instance.
     * @return void
     */
    void returnImageResource(ImageResource *object)
    {
        object->reset();
        _images.push_back(object);
    }

    void freePool()
    {
        // free memory for the objects that still are present in the pool
        while(_images.size())
        {
            ImageResource *obj = _images.front();
            _images.pop_front();
            delete obj;
        }
    }
};


int main()
{
    ObjectPool pool = ObjectPool::getInstance();
    ImageResource *one;
    ImageResource *two;

    /* ConnectionResource will be created. */
    one = pool.getImageResource();
    one->setImageURL("https://www.dataresources.com/server_entry_point.php");
    std::cout << "one = " << one->getImageURL() << " [" << one << "]" << std::endl;

    two = pool.getImageResource();
    two->setImageURL("https://www.another-dataresources.com/another_server_entry_point.php");
    std::cout << "two = " << two->getImageURL() << " [" << two << "]" << std::endl;

    // Return the connection resource to the pool because we don't need it anymore.
    pool.returnImageResource(one);
    pool.returnImageResource(two);

    /* ImageResources will be reused.
     * Notice that the ImageURL of both resources were reset back to zero.
     */
    one = pool.getImageResource();
    std::cout << "one = " << one->getImageURL() << " [" << one << "]" << std::endl;

    two = pool.getImageResource();
    std::cout << "two = " << two->getImageURL() << " [" << two << "]" << std::endl;

    pool.freePool();

    return 0;
}

//-----------------------------------------------------------
/*
Output:

Creating new.
one = https://www.dataresources.com/server_entry_point.php [0x21c6030]
Creating new.
two = https://www.another-dataresources.com/another_server_entry_point.php [0x21c60e0]
Reusing existing.
one =  [0x21c6030]
Reusing existing.
two =  [0x21c60e0]

*/
