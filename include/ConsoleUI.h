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
    int addTransaction(int type); //1 - transaction menu, 2 - dashboard
    int transactionHistory(int type); //1 - transaction menu, 2 - dashboard
    // Wallet features
    int newWallet(); // 1 - wallet menu, 2 - dashboard
    int deleteWallet(DynamicArray<Wallet>& wallet_list); // 1 - wallet menu, 2 - dashboard
    int renameWallet(DynamicArray<Wallet>& wallet_list); // 1 - wallet menu, 2 - dashboard
    // Category features
    int newCategory(int type); // 1 - category menu, 2 - dashboard
    int deleteCategory(DynamicArray<Category>& category_list, int type); // 1 - category menu, 2 - dashboard
    int renameCategory(DynamicArray<Category>& category_list, int type); // 1 - category menu, 2 - dashboard
public:
    int displayDashBoard(); // 1-wallet, 2-trans, 3-category0, 4-category1

    // Wallet -> Category -> Transaction information -> Transaction.cpp
    int transactionManagementMenu(int type); //1-new trans, 2-trans his, 3-dashboard

    // Edit wallet name, delete wallet, add new wallet
    int walletManagementMenu(); //1-new wallet, 2-delete wallet, 3-rename wallet, 4-dashboard

    // Edit category name, delete category, add new category
    int categoryManagementMenu(int type); //
};
