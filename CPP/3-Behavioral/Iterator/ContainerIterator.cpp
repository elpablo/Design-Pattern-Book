#include "ContainerIterator.h"
#include "Container.h"

bool ContainerIterator::is_done()
{
    return _index == _container->_container_pointer + 1;
}

int ContainerIterator::current_item()
{
    return _container->_items[_index];
}

bool operator == (const Container &l, const Container &r)
{
    // Clients ask the container object to create an iterator object
    ContainerIterator *itl = l.create_iterator();
    ContainerIterator *itr = r.create_iterator();

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
