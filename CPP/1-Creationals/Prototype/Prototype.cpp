#include <iostream>
#include <vector>

// Prototype base class
class Filter
{
public:
    virtual ~Filter() {}
    virtual Filter* clone() = 0;
    virtual void applyFilter() = 0;
};

// Factory method used to allocate the prototypes
class Factory
{
public:
    static Filter *makeFilter( int filter_index );

private:
    // This factory has 3 types of prototype
    static Filter *s_prototypes[3];
};

class GaussianBlur : public Filter
{
public:
    /*virtual*/ Filter *clone()
    {
        return new GaussianBlur();
    }
    /*virtual*/ void applyFilter()
    {
        std::cout << "GaussianBlur: applying filter...\n";
    }
};

class Pixelate : public Filter
{
public:
    /*virtual*/ Filter *clone()
    {
        return new Pixelate();
    }
    /*virtual*/ void applyFilter()
    {
        std::cout << "Pixelate: applying filter...\n";
    }
};

class Threshold : public Filter
{
public:
    /*virtual*/ Filter *clone()
    {
        return new Threshold();
    }
    /*virtual*/ void applyFilter()
    {
        std::cout << "Threshold: applying filter...\n";
    }
};

// Initialize the prototypes' list of Filters
Filter *Factory::s_prototypes[] = {
    new GaussianBlur(), new Pixelate(), new Threshold()
};

// Implementation of the Factory method used to create cloned prototypes objects
Filter *Factory::makeFilter( int filter_index )
{
    return s_prototypes[filter_index]->clone();
}

// Use the prototype pattern
int main()
{
    std::vector<Filter *> filters;
    int filter_index;

    // Create some filters
    // 0 => GaussianBlur, 1 => Pixelate, 2 => Threshold
    filters.push_back( Factory::makeFilter( 0 ) );
    filters.push_back( Factory::makeFilter( 2 ) );
    filters.push_back( Factory::makeFilter( 1 ) );

    // Use all the created filters
    for (int i=0; i < filters.size(); ++i)
    {
        filters[i]->applyFilter();
    }
    // free the allocated memory
    for (int i=0; i < filters.size(); ++i)
    {
        delete filters[i];
    }

    return 0;
}

//-----------------------------------------------------------
/*
Output:

GaussianBlur: applying filter...
Threshold: applying filter...
Pixelate: applying filter...

*/
