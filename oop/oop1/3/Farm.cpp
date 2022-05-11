#include "Farm.h"
#include "Cow.h"
#include <iostream>
#include <string>
using namespace std;

void Farm::addCow(Cow c)
{
    static int i = 0;
    arry[i] = c;
    i++;
}
void Farm::supply(string name, double a)
{
    for (int i = 0; i < n; i++)
    {
        if (name == arry[i].getname())
        {
            supplyremaining[i] += a;
        }
    }
}
void Farm::startMeal()
{
    for (int i = 0; i < n; i++)
    {
        if (supplyremaining[i] == 0)
            state[i] = 0;
        else if (supplyremaining[i] < arry[i].getl())
        {
            supplyremaining[i] = 0;
            state[i] = 1;
        }
        else if (supplyremaining[i] > arry[i].getu())
        {
            supplyremaining[i] -= arry[i].getu();
            state[i] = 2;
        }
        else
        {
            supplyremaining[i] = 0;
            state[i] = 3;
        }
    }
}
void Farm::produceMilk()
{
    for (int i = 0; i < n; i++)
    {
        if (state[i] == 0)
            milksum += 0;
        else if (state[i] == 1)
            milksum += (arry[i].getm()/2);
        else if (state[i] == 2 || state[i] == 3)
            milksum += arry[i].getm();
    }
}
double Farm::getMilkProduction()
{
    return milksum;
}