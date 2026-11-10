#pragma once
#include <cassert>
struct Date { 
}; //Tran Tra Khoi Nguyen

template <typename T>
class DynamicArray {
    DynamicArray(int initCap=20);
    ~DynamicArray();
    void push_back(const T &item);
    T& operator[] (int index);
    int size();
    void removeAt(int index);
    void pop_back();
    bool empty();
    T* begin();
    T* end()
}; //Huynh Nghia Nhan