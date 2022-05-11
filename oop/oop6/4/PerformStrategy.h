#pragma once
class PerformStrategy
{
public:
    virtual double getperform() const = 0;
};

class sPerformStrategy : public PerformStrategy
{
    double perform;
public:
    sPerformStrategy(double perf) : perform(perf) {};
    double getperform() const { return perform; }
};

class mPerformStrategy : public PerformStrategy
{
    double perform;
public:
    mPerformStrategy(double perf) : perform(perf) {};
    double getperform() const { return perform; }
};

class lPerformStrategy : public PerformStrategy
{
    double perform;
public:
    lPerformStrategy(double perf) : perform(perf) {};
    double getperform() const { return perform; }
};