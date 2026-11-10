#pragma once
#include <cassert>
struct Date { 
    int day;
    int month;
    int year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
}; //Tran Tra Khoi Nguyen
template <typename T>
class DynamicArray {
    private:
    T* data;
    int currentSize;
    int capacity;
    public:
    DynamicArray(int initCap=20){
        capacity=initCap;
        currentSize = 0;
        data= new T[capacity];
    }
    ~DynamicArray() {
        delete []data;
    }
    void push_back(const T &item){
        if(currentSize>=capacity) {
            capacity*=2;
            T *newData= new T[capacity];
            for (int i=0;i<currentSize;++i){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
        }
        data[currentSize++]=item;
    }
    T& operator[] (int index) {
        assert(index >= 0 && index < currentSize); 
        return data[index];
    }
    int size() const{
        return currentSize;
    }
    void removeAt(int index){
        if (index<0 || index>=currentSize) return;
        for(int i=index;i<currentSize-1;++i){
            data[i] = data[i+1];
        }
        currentSize--;
    }
    void pop_back(){
        if(currentSize<1) return;
        data[currentSize-1]=T(); 
        currentSize--;
    }
    
    bool empty(){
        return currentSize==0;
    }

    T* begin() { return data;}
    const T* begin() const { return data;}

    T* end() { return data+size;}
    const T* end() const { return data+size;}
}; //Huynh Nghia Nhan