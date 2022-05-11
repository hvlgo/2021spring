#pragma once
#include <vector>
#include <string>
using namespace std;

class Instruction
{
public:
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};

class note : public Instruction
{
    string ins;
public:
    note() {}
    note(string c) : ins(c) {}
    void apply(std::vector<int> &vec)
    {
        for (auto i : vec)
        {

        }
    }
    void apply(std::vector<double> &vec)
    {

    }
    void output()
    {

    }
};
