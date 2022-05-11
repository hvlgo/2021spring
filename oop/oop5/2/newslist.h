#pragma once
#include "myfriend.h"

class newslist
{
    std::deque<myfriend> fri;
public:
    void addfriend(const myfriend & f);
    void top(const myfriend & f);
    std::deque<myfriend> & getlist();
};