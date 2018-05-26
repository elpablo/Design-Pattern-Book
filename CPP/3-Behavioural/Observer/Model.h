#ifndef __Subject_h
#define __Subject_h

#include <vector>

class Observer;

class Model
{
    // "independent" functionality
    std::vector<Observer *> _observers; // Coupled only to "interface"
    int _value;

public:
    void attach(Observer *obs)
    {
        _observers.push_back(obs);
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
