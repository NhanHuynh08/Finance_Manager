//Tran Tra Khoi Nguyen
#pragma once
#include "WalletManager.h"
#include "CategoryManager.h"
#include "TransactionManager.h"
#include "utils.h"
#include <iostream>
#include <string>


class ConsoleUI {
private:
    static void clrscr();
    void printTitle(std::string& title);
    void printNavigationMenu(DynamicArray<std::string>& choices);
public:
    void displayDashBoard();

    // Wallet -> Category -> Transaction information -> Transaction.cpp
    static void transactionManagementMenu(int type);

    // Edit wallet name, delete wallet, add new wallet
    static void walletManagementMenu();

    // Edit category name, delete category, add new category
    static void categoryManagementMenu(int type);
};
