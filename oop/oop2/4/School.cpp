//#pragma once
#include "School.h"

School::School(int n)
{
    this -> n = n;
    ddlfighter = new Student[n + 5];

}

void School::add_member(Student s)
{
    static int pos = 0;
    ddlfighter[pos++] = s;
}

School::~School()
{
    delete[] ddlfighter;
}