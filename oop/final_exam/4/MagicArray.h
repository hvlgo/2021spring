#pragma once
#include "Instruction.h"
#define maxn 105
static int i = 0;
class str
{
    string notes;
public:
    str(string c) : notes(c) {}
    void operator+=(int num)
    {
        notes += " += ";
        notes.push_back(num);
        MagicArray::my_ins[i] = note(notes);
    }
};

class MagicArray
{
    static  Instruction* my_ins;
public:
    MagicArray(int num){
        my_ins = new note[num];
    }
    str operator[](int num)
    {
        string s;
        s = "arr[";
        s.push_back(num);
        s += "]"; 
        str result(s);
        my_ins[i++] = note(s);
        return result;
    }
    Instruction* getInstructions()
    {
        return my_ins;
    }
    friend class str;
};