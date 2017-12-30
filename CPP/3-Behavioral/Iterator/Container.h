#ifndef __Stack_h
#define __Stack_h

class ContainerIterator;

class Container
{
    int _items[10];
    int _container_pointer;

public:
    friend class ContainerIterator;
    Container()
    {
        _container_pointer =  - 1;
    }

    void push(int in)
    {
        _items[++_container_pointer] = in;
    }

    int pop()
    {
        return _items[_container_pointer--];
    }

    bool isEmpty()
    {
        return (_container_pointer ==  - 1);
    }

    ContainerIterator *createIterator() const; // Add a createIterator() member
};

#endif
