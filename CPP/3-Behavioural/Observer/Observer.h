#ifndef __Observer_h
#define __Observer_h

#include "Model.h"
#include <iostream>


class Observer
{
    // "dependent" functionality
    Model *_model;
    int _denom;

public:
    Observer(Model *mod, int div)
    {
        _model = mod;
        _denom = div;
        // Observers register themselves with the Model
        _model->attach(this);
    }

    virtual ~Observer() {}

    // Callback called then the observer object notify some change.
    // You must define it in derived classes
    virtual void update() = 0;

protected:
    Model *getSubject()
    {
        return _model;
    }

    int getDivisor()
    {
        return _denom;
    }
};

//-----------------------------------------------------
class DivObserver: public Observer
{
public:
    DivObserver(Model *mod, int div): Observer(mod, div)
    {
    }

    /*virtual*/ void update()
    {
        // "Pull" information of interest
        int v = getSubject()->getVal();
        int d = getDivisor();
        std::cout << v << " div " << d << " is " << v / d << std::endl;
    }
};

//-----------------------------------------------------
class ModObserver: public Observer
{
public:
    ModObserver(Model *mod, int div): Observer(mod, div)
    {
    }

    /*virtual*/ void update()
    {
        int v = getSubject()->getVal();
        int d = getDivisor();
        std::cout << v << " mod " << d << " is " << v % d << std::endl;
    }
};

#endif
