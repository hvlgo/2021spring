//#pragma once
#include "Student.h"

Student Student::no = Student();

ostream& operator<< (ostream& out, Student s)
{
        if (Student::no.getisfind() == false)
        {
            out << "Not Found" << endl;
            Student::no.setisfind(true);
        }
        else
        {
            out << s.getname() << '-';
            out.fill('0');
            out.width(4);
            out << s.getbacktime() << '-';
            out << s.getgrade() << '-';
            out.width(6);
            out << s.getid() << endl;
        }
        return out;
}
istream& operator>> (istream& in, Student& s)
{
    string input;
    in >> input;
    int start;
    start = input.find('-');
    s.name = input.substr(0, start);
    string tmp;
    tmp = input.substr(start + 1, 1);
    s.province = *(tmp.c_str());
    tmp = input.substr(start + 3, 1);
    int t;
    t = atoi(tmp.c_str());
    s.grade = t;
    tmp = input.substr(start + 5, 4);
    t = atoi(tmp.c_str());
    s.backtime = t;
    tmp = input.substr(start + 10);
    t = atoi(tmp.c_str());
    s.id = t;
    return in;
}