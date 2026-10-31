
#include <iostream>
#include <string> // Thêm thư viện này
#include "DynamicArray.h"  
#include "ExpenseCategory.h" 
using namespace std;

class Expense_Transaction {
private:
    double amount;
    string walletID;
    string date;
    string description;
    string categoryID;
public:
    Expense_Transaction();

    void set_Information(std::string d, std::string catID, double money, std::string walID, std::string desc);
    // Date getDate();

    string get_CategoryID();

    double get_Amount();

    string get_WalletID();

    string get_Description();
};

