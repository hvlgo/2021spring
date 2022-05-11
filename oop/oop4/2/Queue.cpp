
#include "Queue.h"

int Queue::add(int idx)
{
    if (idx == 1000)
        return 0;
    else
        return ++idx;
}
void Queue::push(int number)
{
    //if (n == max_n) return;
    n++;
    data[idx_end] = number;
    idx_end = add(idx_end);
}

int Queue::pop()
{
    //if (n == 0) return;
    n--;
    int tmp = data[idx_begin];
    idx_begin = add(idx_begin);
    return tmp;
}