#pragma once
class LevelStrategy
{
public:
    virtual int getBase() const = 0;
};

class P1LStrategy : public LevelStrategy
{
    int base = 2000;
public:
    int getBase() const { return base; }
};

class P2LStrategy : public LevelStrategy
{
    int base = 5000;
public:
    int getBase() const { return base; }
};

class P3LStrategy : public LevelStrategy
{
    int base = 10000;
public:
    int getBase() const { return base; }
};