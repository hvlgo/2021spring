#ifndef FARM_H
#define FARM_H
#include <string>
#include "Cow.h"
using namespace std;
class  Farm
{
    int n;
    Cow arry[105];
    double supplyremaining[105] = {0};
    double milksum = 0;
    int state[105] = {0};
    public:
        void addCow(Cow c);
        void supply(string name, double a);
        void startMeal();
        void produceMilk();
        double getMilkProduction();
        double getsupplyRemaining(int i)
        {
            return supplyremaining[i];
        }
    Farm(int _n)
    {
        this-> n = _n;
    }
};
#endif