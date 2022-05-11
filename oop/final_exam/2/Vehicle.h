#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int max_wheel_num;
    int max_wing_num;
    int wheel = 0;
    int wing = 0;
public:
    void set_max_wheel_num(int num)
    {
        max_wheel_num = num;
    }
    void set_max_wing_num(int num)
    {
        max_wing_num = num;
    }
    void add_wheel()
    {
        wheel++;
    }
    void add_wing()
    {
        wing++;
    }
    bool finished()
    {
        if (wheel >= max_wheel_num && wing >= max_wing_num) return true;
        return false;
    }
    virtual void run()
    {
        cout << "I am running" << endl;  
    }
};