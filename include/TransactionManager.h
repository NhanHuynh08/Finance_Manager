//Huynh Nghia Nhan
#pragma once
#include "CategoryManager.h"
#include "utils.h"
#include <string>

//type 0: expense
//type 1: income
struct Transaction {
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
    DynamicArray<Transaction> transactionData;
    //bool accessData();
public:
    TransactionManager();
    // Add a new transaction
    bool addTransaction(string& id, string& wallet_id, string& category_id, double& amount, Date& date, string& note, int type);

    // Query all transactions
    bool getAllTransaction(DynamicArray<Transaction>& transactions, int type, int& size);

    //Recurring transactions
};