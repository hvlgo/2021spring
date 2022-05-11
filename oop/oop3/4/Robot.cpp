#include "Robot.h"
#include "Part.h"

Robot::Robot(int num)
{
    partneed = num;
    partnumber = 0;
    added = new Part[partneed + 5];
}

Robot::~Robot()
{
    if (added != nullptr)   delete [] added;
}

bool Robot::is_full()
{
    return partneed == partnumber;
}

void Robot::add_part(Part toadd)
{
    added[partnumber++] = toadd;
}

