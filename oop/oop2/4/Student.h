#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Student
{
    bool isfind;
    int id;
    int backtime;
    int grade;
    string name;
    char province;
public:
    static Student no;
    friend istream& operator >> (istream& in, Student& s);
    int getid() const { return id; }
    int getbacktime() const { return backtime; }
    int getgrade() const { return grade; }
    string getname() const { return name; }
    char getprovince() const { return province; }
    bool getisfind() const { return isfind; }
    void setisfind(bool x)
    {
        isfind = x;
    }
    bool operator< (Student& s)
    {
        if (s.backtime > this->backtime)
            return true;
        else if (s.backtime < this->backtime)
            return false;
        else if (s.id > this->id)
            return true;
        return false;
    }
    Student()
    {
        isfind = true;
    }
};
ostream& operator<< (ostream& out, Student s);
istream& operator>> (istream& in, Student& s);


