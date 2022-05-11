#include "Stack.h"

void Stack::push(int number)
{
    //if (n >= max_n) return;
    data[idx_end++] = number;
    n++;

}

int Stack::pop()
{
    //if (n == 0) return;
    n--;
    return data[--idx_end];
}