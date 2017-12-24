#ifndef __Observer_h
#define __Observer_h

#include "Subject.h"
#include <iostream>


class Observer
{
    // "dependent" functionality
    Subject *_model;
    int _denom;

public:
    Observer(Subject *mod, int div)
    {
        _model = mod;
        _denom = div;
        // Observers register themselves with the Subject
        _model->attach(this);
    }

    virtual ~Observer() {}

    // Callback called then the observer object notify some change.
    // You must define it in derived classes
    virtual void update() = 0;

protected:
    Subject *getSubject()
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
    DivObserver(Subject *mod, int div): Observer(mod, div)
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
    ModObserver(Subject *mod, int div): Observer(mod, div)
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
