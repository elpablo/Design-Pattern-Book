#!/usr/bin/env python3


class ImageResource:
    """
    Test class used to demonstrate the ObjectPool pattern
    """
    def __init__(self):
        self.url = ''

    def reset(self):
        self.url = ''


_pool = None


class ObjectPool:
    """
    Singleton class representing the pool of ImageResource objects
    """
    def __init__(self):
        self.images = []

    def get_image_resource(self):
        if len(self.images) == 0:
            print("Creating new resource...")
            return ImageResource()
        else:
            print("Reusing existing resource...")
            return self.images.pop(0)

    def return_image_resource(self, resource):
        """
        Reset the given resource object and make it available for others that need it
        :param resource: Is the object released by the client code that needs to be reinserted into the pool
        :return: None
        """
        resource.reset()
        self.images.append(resource)

    def free_pool(self):
        """
        Remove all the objects from the pool
        :return: None
        """
        self.images.clear()


def shared_pool():
    """
    It checks that the instance of ObjectPool has been created or not and returns it to the caller
    :return: the unique instance of the ObjectPool
    """
    global _pool
    if _pool is None:
        _pool = ObjectPool()

    return _pool


def main():
    # Get the pool object
    pool = shared_pool()

    # Ask to the pool an instance of ImageResource
    one = pool.get_image_resource()
    # Customize it as needed by the client
    one.url = "https://www.dataresources.com/server_entry_point.php"
    print(one.url)

    # Ask another resource object to the pool
    two = pool.get_image_resource()
    # ... and customize it
    two.url = "https://www.another-dataresources.com/another_server_entry_point.php"
    print(two.url)

    # Return the resources to the pool because we don't need them anymore
    pool.return_image_resource(one)
    pool.return_image_resource(two)

    # Ask again the released resource
    one = pool.get_image_resource()
    # it has been reset by the pool, so it is at an initial state
    print(one.url)

    # same thing for thew second resource
    two = pool.get_image_resource()
    print(two.url)

    # Free all the resource objects of the pool
    pool.free_pool()


if __name__ == "__main__":
    main()


"""
Output:

Creating new resource...
https://www.dataresources.com/server_entry_point.php
Creating new resource...
https://www.another-dataresources.com/another_server_entry_point.php
Reusing existing resource...

Reusing existing resource...

"""
