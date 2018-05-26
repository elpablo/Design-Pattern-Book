#include "Strategy.h"

#include <fstream>
#include <string>

class Serializer
{
public:
    Serializer()
    {
        _strategy = NULL;
    }

    void setStrategy(Strategy *s)
    {
        _strategy = s;
    }

    void save()
    {
        _strategy->serialize();
    }

private:
    Strategy *_strategy;
};


int main()
{
    // We have our model that has to be saved
    ObjectData obj(42);

    // Save on disk strategy
    OnDiskStrategy disk(&obj);

    Serializer serializer;
    serializer.setStrategy(&disk);
    serializer.save();

    // Now we want to backup our data on cloud
    // so we build a cloud strategy...
    OnCloudStrategy cloud(&obj);
    serializer.setStrategy(&cloud);
    // ... and apply it.
    serializer.save();

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

Serialize data '42' on local disk.
Serialize data '42' on cloud.

*/
