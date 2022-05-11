#pragma once

#define maxn 1050
#include <vector>
using namespace std;

template <class T> class Container
{
    vector<int> x;
    vector<int> y;
    vector<T> z;
public:
    void insert(int x, int y, T z);
    T* find(int x, int y);
};

template<class T>
void Container<T>::insert(int _x, int _y, T _z)
{
    x.push_back(_x);
    y.push_back(_y);
    z.push_back(_z);
}

template<class T>
T* Container<T>::find(int _x, int _y)
{
    for (int i = 0; i < x.size(); i++)
    {
        if(x[i] == _x && y[i] == _y)
        {
            T* tmp = new T(z[i]);
            return tmp;
        }
    }
    return nullptr;
}