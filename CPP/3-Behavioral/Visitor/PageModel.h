#ifndef __Page_h
#define __Page_h

#include <string>

class Visitor;

class PageBase
{
public:
    virtual ~PageBase() {}
    virtual void accept(Visitor &v) = 0;
};

class Page: public PageBase
{
public:
    /*virtual*/ void accept(Visitor &v);

    std::string text()
    {
        return "Page Text";
    }
};

#endif
