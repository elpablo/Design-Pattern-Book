#ifndef __StackIter_h
#define __StackIter_h

class Stack;

class StackIter
{
    // Design an "iterator" class
    const Stack *_stk;
    int _index;

public:
    StackIter(const Stack *s)
    {
        _stk = s;
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

bool operator == (const Stack &l, const Stack &r);

#endif
