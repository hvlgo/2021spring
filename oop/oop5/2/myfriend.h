#pragma once
#include <deque>
#include <string>
#include <iostream>

class myfriend
{
    int id;
    std::deque<std::string> chat;
public:
    myfriend(int number, const std::string & message);
    void addmessage(const std::string & str);
    int getid() const;
    friend std::ostream & operator << (std::ostream & os, const myfriend & f);
};

std::ostream & operator << (std::ostream & os, const myfriend & f);