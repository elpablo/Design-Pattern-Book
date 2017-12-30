#include "ContainerIterator.h"
#include "Container.h"

bool ContainerIterator::isDone()
{
    return _index == _container->_container_pointer + 1;
}

int ContainerIterator::currentItem()
{
    return _container->_items[_index];
}
