//Tran Tra Khoi Nguyen
#pragma once
#include "WalletManager.h"
#include "CategoryManager.h"
#include "TransactionManager.h"
#include "utils.h"
#include <iostream>


class ConsoleUI {
private:
    void printTitle();
public:
    void displayDashBoard(DynamicArray<Wallet>& list_wallet);

    // Wallet -> Category -> Transaction information -> Transaction.cpp
    void transactionManagementMenu(DynamicArray<Wallet>& list_wallet, CategoryManager& categorySection, int type);

    // Edit wallet name, delete wallet, add new wallet
    void walletManagementMenu(DynamicArray<Wallet>& list_wallet);

    // Edit category name, delete category, add new category
    void categoryManagementMenu(CategoryManager& categorySection);
};
