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
