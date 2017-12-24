#ifndef __Strategy_h
#define __Strategy_h

#include "ObjectData.h"

#include <iostream>

class Strategy
{
public:
    Strategy(ObjectData *d): _data(d)
    {
    }

    virtual ~Strategy() {}

    virtual void serialize() = 0;

protected:
    ObjectData *_data;
};

//-----------------------------------------------------
class OnDiskStrategy: public Strategy
{
public:
    OnDiskStrategy(ObjectData *d): Strategy(d)
    {
    }

    /*virtual*/ void serialize()
    {
        std::cout << "Serialize data '"
                  << _data->getValue()
                  << "' on local disk." << std::endl;
    }
};

//-----------------------------------------------------
class OnCloudStrategy: public Strategy
{
public:
    OnCloudStrategy(ObjectData *d): Strategy(d)
    {
    }

    /*virtual*/ void serialize()
    {
        std::cout << "Serialize data '"
                  << _data->getValue()
                  << "' on cloud." << std::endl;
    }
};

#endif
