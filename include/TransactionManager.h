//Huynh Nghia Nhan
#pragma once
#include "CategoryManager.h"
#include "utils.h"
#include <string>

//type 0: expense
//type 1: income
class Transaction {
public:
    string id;
    string wallet_id;
    string category_id;
    double amount;
    Date date;
    string note;
    int type;
};
class TransactionManager {
private:
    DynamicArray<Transaction> TransactionData;
    //bool accessData();
public:
    TransactionManager();

    // Add a new transaction (update wallet, write log of transaction)
    bool addTransaction(const string& wallet_id, const string& category_id, const double& amount, const Date& date, const string& note, const int type);

    // Query all transactions (store results in variable transactions)
    bool getAllTransaction(DynamicArray<Transaction>& transactions, const int type, int& size);

    //Recurring transactions
};