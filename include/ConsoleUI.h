//Tran Tra Khoi Nguyen
#pragma once
#include "WalletManager.h"
#include "CategoryManager.h"
#include "TransactionManager.h"
#include "utils.h"
#include <iostream>
#include <string>

const int width = 100;
class ConsoleUI {
private:
    static void clrscr();
    void printTitle(std::string& title);
    void printWalletList(DynamicArray<Wallet>& wallet_list);
    void printCategoryList(DynamicArray<Category>& category_list);
    int userChoice(DynamicArray<std::string>& choices);

    // Transaction features
    int addTransaction(int type);
    int transactionHistory(int type);

public:
    int displayDashBoard();

    // Wallet -> Category -> Transaction information -> Transaction.cpp
    int transactionManagementMenu(int type);

    // Edit wallet name, delete wallet, add new wallet
    static void walletManagementMenu();

    // Edit category name, delete category, add new category
    static void categoryManagementMenu(int type);
};
