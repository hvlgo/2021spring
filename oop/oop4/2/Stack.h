#ifndef __STACK
#define __STACK

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Stack: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
    public:
        Iterator(int *_data, int pos) : IteratorBase(_data, pos){

        }

        Iterator(const Iterator & src) : IteratorBase(src.data, src.idx) {}
        Iterator operator++(int )
        {
            Iterator it(*this);
            this->idx++;
            return it;
        }
        Iterator operator++()
        {
            this->idx++;
            return *this;
        }
    // TODO
    };
    Stack(int _n = 0) : LinearDataStruct(_n){

    }
    Iterator begin()
    {
        return Stack::Iterator(data, idx_begin);
    }
    Iterator end()
    {
        return Stack::Iterator(data, idx_end);
    }
    void push(int number);
    int pop();
    // TODO
};


#endif