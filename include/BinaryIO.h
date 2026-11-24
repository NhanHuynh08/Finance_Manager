#pragma once
#include "utils.h"
#include <iostream>
#include <fstream>
#include <type_traits>
namespace BinaryIO {
    //Date type : int, long long , char, bool and class : Date, Wallet....
    template <typename T>
    void write(std::ofstream &out, const T& val) {
        //int, long long, double ....
        if constexpr (std::is_arithmetic_v<T>) {
            out.write(reinterpret_cast <const char *> (&val) , sizeof(T));
        }

        else {
            //Class struct
            val.saveBinary(out);
        }
    }
    template <typename T>
    bool read(std::ifstream &in, T& val) {
        if constexpr( std::is_arithmetic_v<T>){
            return static_cast<bool> (in.read(reinterpret_cast <char *> (&val), sizeof(T)));
        }

        else {
            return val.loadBinary(in);
        }
    }
    //Date type: string (C++)
    inline void write(std::ofstream& out, const std::string& str){
        int len=static_cast<int> (str.size());
        BinaryIO::write(out,len);

        if(len>0){
            out.write(str.c_str(),len);
        }
    }
    inline bool read(std::ifstream& in, std::string& str){
        int len=0;
        if(!BinaryIO::read(in,len) || len<0 || len>1000000) return false;

        str.assign(len,'\0');
        if(len>0){
            in.read(&str[0],len);
        }
        return static_cast<bool>(in);
    }
    //Date type: DynamicArray
    template <typename T>
    void write(std::ofstream& out, const DynamicArray<T>& arr){
        int count=arr.size();
        BinaryIO::write(out,count);

        for(int i=0;i<count;++i){
            BinaryIO::write(out,arr[i]);
        }
    }
    template <typename T>
    bool read(std::ifstream& in, DynamicArray<T>& arr){
        int count=0;
        if(!BinaryIO::read(in,count) || count<0 || count>1000000) return false;
        
        arr.clear();
        for(int i=0; i<count;++i){
            T item{};
            if(!BinaryIO::read(in,item)) return false;
            arr.push_back(item);
        }
        return true;
    }
    //Permit Nghia Nhan to edit this public header
}