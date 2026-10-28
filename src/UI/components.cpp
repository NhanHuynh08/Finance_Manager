#include "../../include/UI/components.h"
#include <iostream>
using namespace std;

void printTitle(const std::string& title) {
    if (title.length()>=50) return;
    int width=50;
    cout << std::string (width, '=') << endl;
    cout << std::string ((width - title.length())/2, ' ')
         << title << std::string ((width-title.length())/2, ' ') << endl;
    cout << std::string (width, '=') << endl;
    return;
}