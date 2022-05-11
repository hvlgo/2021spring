#include "Calculator.h"
#include <iostream>
using namespace std;

int Calculator::get_base() const
{
    return my_LevelStrategy->getBase();
}

int Calculator::get_total(int base) const
{
    double perform = my_PerformStrategy->getperform();
    if (perform < 0.5)  return base + 1000;
    else if (perform < 0.8) {
        // cout << perform << endl;
        // cout << base << endl;
        // cout << 0.691 * 2000 + 2000 <<endl;
        // cout << fixed <<  double(base) * perform + base << endl;
        // cout <<int (perform * double(base) + base) << endl;
        return double(base) * perform + base;
    }
    else return base + base * 2 * perform;
}