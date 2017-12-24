#include <iostream>
#include <vector>

// "interface" Filter class
// (lowest common denominator between single and grouped objects)
class FilterInterface
{
public:
    virtual ~FilterInterface() {}
    virtual void apply_filter() = 0;
};

class Filter: public FilterInterface
{
    // Single object class
    int _value;

public:
    Filter(int val)
    {
        _value = val;
    }

    /*virtual*/ void apply_filter()
    {
        std::cout << _value << " ";
    }
};

class FilterGroup: public FilterInterface
{
    // Group objects class
    std::vector<FilterInterface *> _children; // "container" coupled to the interface

public:
    ~FilterGroup()
    {
        for (int i = 0; i < _children.size(); i++)
        {
            delete _children[i];
        }
        _children.clear();
    }

    // "container" class coupled to the interface
    void add(FilterInterface *f)
    {
        _children.push_back(f);
    }

    /*virtual*/ void apply_filter()
    {
        for (int i = 0; i < _children.size(); i++)
        {
            // Use polymorphism to delegate to children
            _children[i]->apply_filter();
        }
    }
};

int main()
{
    // Build a single filter
    Filter *single = new Filter(42);

    // Setup a group of filters into a group
    FilterGroup *group = new FilterGroup();
    for (int i = 0; i < 4; ++i)
    {
        group->add(new Filter(i));
    }

    FilterGroup *mega_group = new FilterGroup();
    // Build a group of group of filters
    FilterGroup *group2 = new FilterGroup();
    for (int j = 5; j < 10; ++j)
    {
        group2->add(new Filter(j));
    }
    mega_group->add(group2);

    // From now on we can use the base
    // class API for single filters or groups

    // Apply the single filter
    single->apply_filter();
    std::cout << std::endl;

    // Apply the filter's group
    group->apply_filter();
    std::cout << std::endl;

    // Apply the filter's mega_group
    mega_group->apply_filter();
    std::cout << std::endl;

    delete single;
    delete group;
    delete mega_group;

    return 0;
}

//-----------------------------------------------------------
/*
Output:

42
0 1 2 3
5 6 7 8 9

*/
