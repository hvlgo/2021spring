#pragma once

#include "Robot.h"
class Bob : public Robot
{
public:
    Bob(int num) : Robot(num) {}
    int run();
};

ostream& operator<<(ostream& out, const Bob& Bob);