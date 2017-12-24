#include "StackIter.h"
#include "Stack.h"

bool StackIter::is_done()
{
    return _index == _stk->_stack_pointer + 1;
}

int StackIter::current_item()
{
    return _stk->_items[_index];
}

bool operator == (const Stack &l, const Stack &r)
{
    // Clients ask the container object to create an iterator object
    StackIter *itl = l.create_iterator();
    StackIter *itr = r.create_iterator();

    // Clients use the first(), is_done(), next(), and current_item() protocol
    for (itl->first(), itr->first(); !itl->is_done(); itl->next(), itr->next())
    {
        if (itl->current_item() != itr->current_item())
        {
            break;
        }
    }
    bool answer = itl->is_done() && itr->is_done();

    delete itl;
    delete itr;

    return answer;
}
