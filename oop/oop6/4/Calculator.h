#pragma once
#include "LevelStrategy.h"
#include "PerformStrategy.h"

class Calculator
{
    LevelStrategy* my_LevelStrategy;
    PerformStrategy* my_PerformStrategy;
public:
    Calculator(LevelStrategy* m_LevelStrategy, PerformStrategy* m_PerformStrategy) : my_LevelStrategy(m_LevelStrategy), my_PerformStrategy(m_PerformStrategy) {}
    int get_base() const;
    int get_total(int base) const;
};