#include <iostream>
#include <vector>

class Item
{
public:
    virtual ~Item() {}
    virtual void do_something() = 0;
};

class FileItem : public Item
{
public:
    /*virtual*/ void do_something()
    {
        std::cout << "calculate checksum..." << std::endl;
    }
};

class NullItem : public Item
{
public:
    /*virtual*/ void do_something()
    {
    }
};


int main()
{
    std::vector<Item *> items;
    items.push_back(new FileItem);
    items.push_back(new NullItem);

    std::cout << "Item 0 (Active): "; items[0]->do_something();
    std::cout << "Item 1 (Null): "; items[1]->do_something();
    std::cout << std::endl;

    return 0;
}

//------------------------------------------------------------------------------
/*
Output:

Item 0: calculate checksum...
Item 1:

*/
