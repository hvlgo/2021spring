#pragma once
#include "what.h"
#include <string>
#include <iostream>
using namespace std;

class Alien : public WhatCanMotion, public WhatCanSpeak
{
    string name;
public:
    Alien(string _name) : name(_name)   {}
    void speak()
    {
        cout << name << " is speaking" << endl;
    }
    void motion()
    {
        cout << name << " is moving" << endl;
    }
    void stop()
    {
        cout << name << " stops" << endl;
    }
    ~Alien()
    {
        
    }
};