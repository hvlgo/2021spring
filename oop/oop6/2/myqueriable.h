#pragma once
#include <vector>
#include <list>
#include <functional>

template<class T>
class MyQueriable
{
    std::vector<T> data;
public:
    int size() const {return data.size();}
    T operator[] (size_t i) const {return data[i];}
    MyQueriable<T> where(std::function<T(T)> f)
    {
        MyQueriable<T> result;
        for (auto k : data)
            if(f(k))    result.data.push_back(k);
        return result;
    }
    MyQueriable<T> apply(std::function<T(T)> f)
    {
        MyQueriable<T> result;
        for (auto k : data)
            result.data.push_back(f(k));
        return result;
    }
    T sum()
    {
        T num = 0;
        for (auto k : data)
            num += k;
        return num;
    }
    template<class T1>
    friend MyQueriable<T1> from(const std::vector<T1> &src);
    template<class T1>
    friend MyQueriable<T1> from(const std::list<T1> &src);

};

template<class T>
MyQueriable<T> from(const std::vector<T> &src)
{
    MyQueriable<T> a;
    copy(src.begin(), src.end(), std::back_inserter(a.data));
    return a;
}

template<class T>
MyQueriable<T> from(const std::list<T> &src)
{
    MyQueriable<T> a;
    copy(src.begin(), src.end(), std::back_inserter(a.data));
    return a;
}