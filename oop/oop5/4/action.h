#pragma once
#include "animal.h"
#include <vector>

void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone)
{
    Dog* tmp = dynamic_cast<Dog*>(animal);
    if (tmp != nullptr)
        dogzone.push_back(std::move(*tmp));
    else
    {
        Bird* b = dynamic_cast<Bird*>(animal);
        birdzone.push_back(std::move(*b));
    }
}