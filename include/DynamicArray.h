#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
template <typename T>
class DynamicArray {
    private:
    T* data;
    int currentSize;
    int capacity;
    public:
    //Ham khoi tao, tu dong cap phat bo nho
    DynamicArray(int initCap=20){
        capacity=initCap;
        currentSize = 0;
        data= new T[capacity];
    }
    //Ham thu hoi, tranh memory leak
    ~DynamicArray() {
        delete []data;
    }
    void push_back(const T &item){
        //cap them bo nho khi mang da day
        if(currentSize>=capacity) {
            capacity*=2;
            T *newData= new T[capacity];
            for (int i=0;i<currentSize;++i){
                newData[i] = data[i];
            }
            // mang newData se tu xoa khi ra khoi khoi lenh
            delete []data;
            data = newData;
        }
        //current++ la lay gia tri truoc sau do moi luu gia tri
        data[currentSize++]=item;
    }
    // Ham lay gia tri giong vector[i];
    T& operator[] (int index) {
        return data[index];
    }
    //Ham tra ve kich thuoc mang, const de mang khong thay doi gia tri bien duoc tra ve
    int size() const{
        return currentSize;
    }
    //removeAt la xoa phan tu tai vi tri index
    void removeAt(int index){
        //neu index khong ton tai se thoat ngay
        if (index<0 || index>=currentSize) return;
        for(int i=index;i<currentSize-1;++i){
            data[i] = data[i+1];
        }
        //giam do lon cua ham
        currentSize--;
    }
};
#endif