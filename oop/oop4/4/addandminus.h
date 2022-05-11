#pragma once
#include "operation.h"

class add : public OperationNodeTwo
{
public:
    add(string name, Node * x1, Node * x2) : OperationNodeTwo(name, x1, x2) {}
    void UpdateValue();
};

class minus : public OperationNodeTwo
{
public:
    minus(string name, Node * x1, Node * x2) : OperationNodeTwo(name, x1, x2) {}
    void UpdateValue();
};