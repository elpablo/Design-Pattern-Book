#ifndef __Stack_h
#define __Stack_h

class StackIter;

class Stack
{
    int _items[10];
    int _stack_pointer;

public:
    friend class StackIter;
    Stack()
    {
        _stack_pointer =  - 1;
    }
    void push(int in)
    {
        _items[++_stack_pointer] = in;
    }
    int pop()
    {
        return _items[_stack_pointer--];
    }
    bool is_empty()
    {
        return (_stack_pointer ==  - 1);
    }
    StackIter *create_iterator() const; // Add a create_iterator() member
};

#endif
