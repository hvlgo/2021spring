#include "addandminus.h"

void add::UpdateValue()
{
    this->value_ = input1->value() + input2->value();
}

void minus::UpdateValue()
{
    this->value_ = input1->value() - input2->value();
}