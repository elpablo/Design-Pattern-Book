#ifndef __Subject_h
#define __Subject_h

#include <vector>

class Observer;

class Subject
{
    // "independent" functionality
    std::vector< Observer * > _views; // Coupled only to "interface"
    int _value;

public:
    void attach(Observer *obs)
    {
        _views.push_back(obs);
    }

    void setVal(int val)
    {
        _value = val;
        notify();
    }

    int getVal()
    {
        return _value;
    }

    void notify();
};

#endif
