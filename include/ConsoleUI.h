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

public:
    void displayDashBoard(); // 1-wallet, 2-trans, 3-category0, 4-category1

    // Wallet -> Category -> Transaction information -> Transaction.cpp
    void transactionManagementMenu(int type); //1-new trans, 2-trans his, 3-dashboard

    // Edit wallet name, delete wallet, add new wallet
    void walletManagementMenu(); //1-new wallet, 2-delete wallet, 3-rename wallet, 4-dashboard

    // Edit category name, delete category, add new category
    void categoryManagementMenu(int type); //1-new category, 2-delete category, 3-rename category, 4-dashboard

    // Transaction features
    void addTransaction(int type); //1 - transaction menu, 2 - dashboard
    void transactionHistory(int type); //1 - transaction menu, 2 - dashboard
    // Wallet features
    void newWallet(); // 1 - wallet menu, 2 - dashboard
    void deleteWallet(DynamicArray<Wallet>& wallet_list); // 1 - wallet menu, 2 - dashboard
    void renameWallet(DynamicArray<Wallet>& wallet_list); // 1 - wallet menu, 2 - dashboard
    // Category features
    void newCategory(int type); // 1 - category menu, 2 - dashboard
    void deleteCategory(DynamicArray<Category>& category_list, int type); // 1 - category menu, 2 - dashboard
    void renameCategory(DynamicArray<Category>& category_list, int type); // 1 - category menu, 2 - dashboard
};
