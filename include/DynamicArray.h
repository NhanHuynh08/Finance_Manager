#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <cassert>
template <typename T>
/*
    DynamicArray<int> arr;
    arr.push_back(2) -> arr[0]=2
    arr.size() -> tra ve kich thuoc hien tai
    arr.removeAt(0) -> xoa phan tu tai index =0
    arr[100] -> lay gia tri tai index=100 trong arr
    arr.pop_back() -> loai bo phan tu cuoi cua arr
    arr.empty() -> tra ve true/false kiem tra arr co rong khong.
    arr.begin()-> tra ve pointer o vi tri dau
    arr.end() -> tra ve pointer sau phan tu cuoi
*/
class DynamicArray {
    private:
    T* data;
    int currentSize;
    int capacity;
    public:
    //Ham khoi tao, no se tu dong cap bo nho cho mang.
    DynamicArray(int initCap=20){
        capacity=initCap;
        currentSize = 0;
        data= new T[capacity];
    }
    //Ham thu hoi, no se tu dong xoa khi ra ngoai scope, tranh memory leak
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
        assert(index >= 0 && index < currentSize); // tranh loi lay gia tri noai bien
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
    void pop_back(){
        if(currentSize<1) return;
        data[currentSize-1]=T(); // dua phan tu cuoi ve gia tri mac dinh 
        currentSize--;
    }
    
    bool empty(){
        return currentSize==0;
    }

    T* begin() { return data;}
    const T* begin() const { return data;}

    T* end() { return data+size;}
    const T* end() const { return data+size;}
};
#endif