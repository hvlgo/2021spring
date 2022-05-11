#include "Alice.h"

int Alice::run()
{
    int sum = 0;
    for (int i = 0; i < partneed; i++)
    {
        sum += added[i].getnumber();
    }
    return sum;
}

ostream& operator<<(ostream& out, const Alice& alice)
{
    out << "Build robot Alice";
    return out; 
}