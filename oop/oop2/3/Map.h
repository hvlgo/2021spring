#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    int size();
    int operator[] (string s) const
    {
        bool find = false;
        for (int i = 0; i < sz; i++)
        {
            if (data[i].hasKey(s))
            {
                find = true;
                return data[i].getVal();
            }
        }
        if (!find)
        {
            return 0;
        }
    }
    int & operator[] (string s)
    {
        bool find = false;
        for (int i = 0; i < sz; i++)
        {
            if (data[i].hasKey(s))
            {
                find = true;
                return data[i].getVal();
            }
        }
        if (!find)
        {
            data[sz++].reset(s, 0);
            return data[sz - 1].getVal();
        }
    }
    ~Map();
    // TODO
};