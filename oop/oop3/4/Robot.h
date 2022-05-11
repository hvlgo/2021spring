#pragma once

#include "Part.h"
#include <iostream>
#include <string>
using namespace std;

class Robot
{
protected:
    int partneed;
    int partnumber;
    Part* added;
public:
    Robot(int num);
    ~Robot();
    bool is_full();
    void add_part(Part toadd);
    int run();
};