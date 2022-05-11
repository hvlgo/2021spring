#include "Bob.h"
#include <cmath>
int Bob::run()
{
    int sum = 0;
    for (int i = 0; i < partneed; i++)
    {
        sum += pow(added[i].getnumber(), 2);
    }
    return sum;
}

ostream& operator<<(ostream& out, const Bob& Bob)
{
    out << "Build robot Bob";
    return out; 
}