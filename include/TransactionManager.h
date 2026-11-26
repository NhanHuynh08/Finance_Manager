//Huynh Nghia Nhan
#pragma once
#include "CategoryManager.h"
#include "utils.h"
#include <string>
#include "WalletManager.h"
//type 0: expense
//type 1: income

class Month_Transaction{
public: // should be public for simplify 
    Date begin, end; 
    string wallet_id; 
    string category_id; 
    double amount; 
    string note; 
    int type; 
    void saveBinary(ofstream& Out) const; 
    bool loadBinary(ifstream& In); 
};

class Transaction {
public:
    string id;
    string wallet_id;
    string category_id;
    double amount;
    Date date;
    string note;
    int type;
    void saveBinary(ofstream& Out) const ; 
    bool loadBinary(ifstream& In); 
};
class TransactionManager {
private:
    string filePath = "data/Transaction.bin";
    int inCount;
    int exCount;
    bool accessDate();
    bool saveDate();
    DynamicArray<Transaction> TransactionData; // history of transactions 
    DynamicArray<Month_Transaction> RecurringData; // reminder note for monthly basis transaction
    // save or load TransactionDate and then RecurringData
    //bool accessData();
    bool loadTransactionManager(); 
    bool saveTransactionManager(); 
public:
    TransactionManager(); 
    // Add a new transaction (update wallet, write log of transaction)
    ~TransactionManager(); 
    bool addTransaction(const string& wallet_id, const string& category_id, const double& amount, const Date& date, const string& note, const int type);

    // Query all transactions (store results in variable transactions)
    bool getAllTransaction(DynamicArray<Transaction>& transactions, const int type);

    //Recurring transactions
};
inline TransactionManager TM;