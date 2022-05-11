#ifndef COW_H
#define COW_H
#include <string>
class Cow
{
    std::string name;
    double l;
    double u;
    double m;
    public:
    Cow(std::string _name, double _l, double _u, double _m)
    {
        this->name = _name;
        this->l = _l;
        this->u = _u;
        this->m = _m;
    }
    Cow()
    {
        return ;
    }
    std::string getname()
    {
        return this->name;
    }
    double getl()
    {
        return this->l;
    }
    double getu()
    {
        return this->u;
    }
    double getm()
    {
        return this->m;
    }
};
#endif