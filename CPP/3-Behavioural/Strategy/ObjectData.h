#ifndef __ObjectData_h
#define __ObjectData_h

class ObjectData
{
    int _val;

public:
    ObjectData(int v) : _val(v)
    {
    }

    int getValue()
    {
        return _val;
    }

    void setValue(int v)
    {
        _val = v;
    }
};

#endif
