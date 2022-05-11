#pragma once
#include "Node.h"
#include <iostream>

class Vector {
private:
    int capacity; //容量，即该对象最多可以储存多少个元素
    int len;      //当前元素长度
    Node* array;  //指向元素数组头的指针
public:
    Vector(int n); //初始化Vector，容量设定为n。
    ~Vector();
    Vector(const Vector & other);
    Vector(Vector && other);
    Vector & operator=(const Vector & other);
    Vector & operator=(Vector && other);
    Node& operator [] (int pos);
    void append(int value);   //在数组的尾部添加一个指定值的元素，即Node(value)。保证插入后长度不会大于容量。
    void insert(int pos, int value);  //在数组的指定位置插入新元素(即Node(value))，其他元素顺次右移。保证插入后长度不会大于容量。
    void swap(int pos1, int pos2);    //交换数组中指定位置的元素
    void dilatation();                //将目前Vector中的数组容量翻倍。提示：你需要先申请更大的数组，然后将当前元素信息移动过去。
    int getlen();                     //获取当前Vector的长度。
};