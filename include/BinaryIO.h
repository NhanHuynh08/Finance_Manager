#pragma once
#include "utils.h"
#include <iostream>
#include <fstream>

namespace BinaryIO {
    //Date type : int, long long , char, bool and class : Date, Wallet....
    template <typename T>
    void write(std::ofstream &out, const T& val);
    template <typename T>
    bool read(std::ifstream &in, const T& val);
    //Date type: string (C++)
    inline void write(std::ofstream& out, const std::string& str);
    inline bool read(std::ifstream& in, std::string& str);
    //Date type: DynamicArray
    template <typename T>
    void write(std::ofstream& out, const DynamicArray<T>& arr);
    template <typename T>
    bool read(std::ifstream& in, DynamicArray<T>& arr);
    //Permit Nghia Nhan to edit this public header
}