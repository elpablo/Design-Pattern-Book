#ifndef __StackIter_h
#define __StackIter_h

class Container;

class ContainerIterator
{
    // Design an "iterator" class
    const Container *_container;
    int _index;

public:
    ContainerIterator(const Container *s)
    {
        _container = s;
    }

    void first()
    {
        _index = 0;
    }

    void next()
    {
        _index++;
    }

    bool is_done();

    int current_item();
};

#endif
