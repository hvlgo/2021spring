#ifndef __ITERATORBASE
#define __ITERATORBASE

class IteratorBase {
    
protected:
    int* data;
    int idx;

public:

    IteratorBase(int* _data, int _idx): data(_data), idx(_idx) {

    }

    bool operator != (const IteratorBase &other)
    {
        if ((*this).idx == other.idx)
            return false;
        else
            return true;
    }
    int operator *()
    {
        return (*this).data[idx];
    }
    // TODO

};


#endif