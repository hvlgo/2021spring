#include "Part.h"

Part::Part()
{
    number = 0;
}

Part::Part(int id)
{
    number = id;
}

int Part::getnumber()
{
    return number;
}