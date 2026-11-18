#include "include/ConsoleUI.h"
#include "include/utils.h"
#include "include/CategoryManager.h"
#include "include/TransactionManager.h"
#include "include/WalletManager.h"
#include <iostream>



using namespace std;
int main() {
    CategoryManager CategoryManager();
    TransactionManager TransactionManager();
    WalletManager WalletManager();
    ConsoleUI UI;
    UI.displayDashBoard();
    std::cout << "Program exited successfully, have a nice day!" << '\n';
    return 0;
}