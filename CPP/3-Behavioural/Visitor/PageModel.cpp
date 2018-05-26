#include "PageModel.h"
#include "Visitor.h"

void Page::accept(Visitor &v)
{
    v.visit(this);
}
