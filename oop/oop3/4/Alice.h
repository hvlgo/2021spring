#pragma once

#include "Robot.h"
class Alice : public Robot
{
public:
    Alice(int num) : Robot(num) {}
    int run();
};

ostream& operator<<(ostream& out, const Alice& alice);