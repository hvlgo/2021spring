#ifndef __QUEUE
#define __QUEUE

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Queue: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
    public:
        Iterator(int *_data, int pos) : IteratorBase(_data, pos){

        }

        Iterator(const Iterator & src) : IteratorBase(src.data, src.idx) {}
        Iterator operator++(int )
        {
            Iterator tmp(*this);
            if (tmp.idx == 1000)
                this->idx = 0;
            else
                this->idx++;
            return tmp;
        }
        Iterator operator++()
        {
            if ((*this).idx == 1000)
                this->idx = 0;
            else
                this->idx++;
            return *this;
        }
        // TODO
    
    };
    Queue(int _n = 0) : LinearDataStruct(_n){

    }
    void push(int number);
    int pop();
    int add(int idx);
    Iterator begin()
    {
        return Queue::Iterator(data, idx_begin);
    }
    Iterator end()
    {
        return Queue::Iterator(data, idx_end);
    }
    // TODO
};

#endif