#include "Vector.h"
using namespace std;

Vector::Vector(int n)
{
    capacity = n;
    len = 0;
    array = new Node[capacity];
}

Vector::~Vector()
{
    if (array != nullptr) delete [] array;
}

Vector::Vector(const Vector & other) : capacity(other.capacity), len(other.len){
    array = new Node[capacity];
    for (int i = 0; i < len; i++)
    {
        array[i] = other.array[i];
    }
}

Vector::Vector(Vector &&other) : capacity(other.capacity), len(other.len), array(other.array)
{
    other.array = nullptr;
    other.len = 0;
    other.capacity = 0;
}

Vector & Vector::operator=(const Vector & other)
{
    if (this != &other){
        capacity = other.capacity;
        len = other.len;
        if (array) delete [] array;
        array = new Node[capacity];
        for (int i = 0; i < len; i++)
        {
            array[i] = other.array[i];
        }
    }
    return *this;
}

Vector & Vector::operator=(Vector &&other)
{
    if (this != &other){
        if (array) delete [] array;
        array = other.array;
        len = other.len;
        capacity = other.capacity;
        other.array = nullptr;
        other.len = 0;
        other.capacity = 0;
    }
    return *this;
}

Node& Vector::operator[](int pos)
{
    return array[pos];
}

void Vector::append(int value)
{
    array[len++] = Node(value);
}

void Vector::insert(int pos, int value)
{
    for (int i = len; i > pos; i--)
    {
        array[i] = move(array[i - 1]);
    }
    array[pos] = Node(value);
    len++;
}

void Vector::swap(int pos1, int pos2)
{
    Node tmp(move(array[pos1]));
    array[pos1] = std::move(array[pos2]);
    array[pos2] = std::move(tmp);
}

void Vector::dilatation()
{
    capacity *= 2;
    Node *newarray = new Node[capacity];
    for (int i = 0; i < len; i++)
    {
        newarray[i] = std::move(array[i]);
    }
    delete[] array;
    array = newarray;
}

int Vector::getlen()
{

    return len;
}