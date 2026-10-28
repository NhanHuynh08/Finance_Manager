#include "../../include/UI/components.h"
#include "../../include/UI/screens.h"
#include <iostream>
using namespace std;

void dashBoard(int balance/*, DynamicArray<wallet>& wallets*/) {
    printTitle("DASHBOARD (MAN HINH CHINH)");
    cout << "- Tong so du: " << balance << " VND" << endl;
    cout << "- Danh sach vi:" << endl;
    /*for (wallet wallet: wallets) {
        cout << "       + " << wallet.name << ": " << wallet.balance << endl;
    }*/
   
    return;
}