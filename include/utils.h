#pragma once
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime> 
struct Date {  // all function in struct is inline 
private: 
    bool LeapYear();
    int getDay_of_Month(); 
public:
    int day=1;
    int month=1;
    int year=1;
    // 1 meaning d1 > d2, -1 meaning d1 < d2, 0 meaning d1 = d2 
    void One_more_month(const int& max_day); 
    static int compared(const Date& d1, const Date& d2);

    static Date get_current_date();
    //Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void displayDate();
    void saveBinary(std::ofstream& Out) const;

    bool loadBinary(std::ifstream& In);
}; 
//Tran Tra Khoi Nguyen

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
    const T& operator [] (int index) const {
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
    const T* end() const { return data+currentSize;}
    void clear(){
        delete [] data;
        capacity=20;
        currentSize=0;
        data=new T[capacity];
    }
}; //Huynh Nghia Nhan