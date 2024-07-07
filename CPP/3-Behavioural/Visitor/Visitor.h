#ifndef __Visitor_h
#define __Visitor_h

#include <string>
#include <algorithm>


class Visitor
{
public:
    virtual ~Visitor() {}
    virtual void visit(Page *e) = 0;
};

//-----------------------------------------------------
class UppercaseVisitor: public Visitor
{
    std::string _str;

public:
    /*virtual*/ void visit(Page *p)
    {
        this->_str = p->text();
        std::transform(this->_str.begin(), this->_str.end(),this->_str.begin(), ::toupper);
    }

    std::string text()
    {
        return this->_str;
    }
};

//-----------------------------------------------------
class LowercaseVisitor: public Visitor
{
    std::string _str;

public:
    /*virtual*/ void visit(Page *p)
    {
        this->_str = p->text();
        std::transform(this->_str.begin(), this->_str.end(),this->_str.begin(), ::tolower);
    }

    std::string text()
    {
        return this->_str;
    }
};

#endif
