#pragma once
#include "Student.h"

class School
{
    int n;
    Student * ddlfighter;
public:
    School (int n);
    void add_member(Student s);
    ~School ();
    friend ostream& operator<< (ostream& out, Student s);
    
    Student operator[] (int sid)
    {
        for (int i = 0; i < n; i++)
        {
            if (ddlfighter[i].getid() == sid)
                return ddlfighter[i];
            else if (i == n - 1)
            {
                Student::no.setisfind(false);
            }
        }
    }
    Student operator[] (string name)
    {
        for (int i = 0; i < n; i++)
        {
            if (ddlfighter[i].getname() == name)
                return ddlfighter[i];
            else if (i == n - 1)
            {
                Student::no.setisfind(false);
            }
        }
    }
    Student operator[] (char province)
    {
        bool find = false;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (ddlfighter[i].getprovince() == province)
            {
                find = true;
                //cout << ddlfighter[pos].getprovince() << endl;
                if (!(ddlfighter[pos].getprovince() == province))
                    pos = i;
                else if (ddlfighter[pos] < ddlfighter[i])
                    pos = i;//以后注意这里
            }
        }
        if (find == false)
        {
                Student::no.setisfind(false);
        }
        else
        {
            return  ddlfighter[pos];
        }
    }
};