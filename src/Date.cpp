#include "include/utils.h" 

bool Date::LeapYear(){ 
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)); 
}

int Date::getDay_of_Month(){ 
    if (month == 2) return (LeapYear()) ? 29 : 28; 
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31; 
    return 30; 
}

void Date::One_more_month(const int& max_day){ 
    if (month == 12){ 
        ++year; 
        month = 1;
    }else ++month; 
    day = std::min(max_day, getDay_of_Month());
}

int Date::compared(const Date& d1, const Date& d2){ 
    if (d1.year != d2.year) return (d1.year > d2.year) ? 1 : -1;
    if (d1.month != d2.month) return (d1.month > d2.month) ? 1 : -1; 
    if (d1.day == d2.day) return 0; 
    else return (d1.day > d2.day) ? 1 : -1; 
}

Date Date::get_current_date(){
    std::time_t now = std::time(nullptr); 
    std::tm* local_time = std::localtime(&now); 
    return Date{local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900}; 
}
//Date(int d, int m, int y) : day(d), month(m), year(y) {}
void Date::displayDate() {
    std::cout << day << '-' << month << '-' << year;
}
void Date::saveBinary(std::ofstream& Out) const { // tránh dùng # include "BinaryIO.h" --> gây circular include
    Out.write(reinterpret_cast<const char*>(&day), sizeof(int)); 
    Out.write(reinterpret_cast<const char*>(&month), sizeof(int)); 
    Out.write(reinterpret_cast<const char*>(&year), sizeof(int)); 
} 

bool Date::loadBinary(std::ifstream& In){ 
    return (
        In.read(reinterpret_cast<char*>(&day), sizeof(int)) && 
        In.read(reinterpret_cast<char*>(&month), sizeof(int)) && 
        In.read(reinterpret_cast<char*>(&year), sizeof(int))
    ); 
}