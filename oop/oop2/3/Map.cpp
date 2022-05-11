#include "Map.h"

Map::Map(int n)
{
    Pair *array = new Pair[n];
    data = array;
    sz = 0;
}

int Map::size()
{
    return sz;
}

Map::~Map()
{
    delete[] data;
}