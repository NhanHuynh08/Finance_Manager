
#include <bits/stdc++.h>
#include <string> // Thêm thư viện này
#include "../include/DynamicArray.h"  
#include "../include/ExpenseCategory.h" 
#include "../include/Expense.h"
#include "../include/Wallet.h"
using namespace std;

Expense_Transaction::Expense_Transaction() 
    : amount(0.0), walletID(""), date(""), description(""), categoryID("") {}


void Expense_Transaction::set_Information(string d, string catID, double money, string walID, string desc) {
    date = d;
    categoryID = catID;
    amount = money;
    walletID = walID;
    description = desc;
}
// Date getDate() const { return date; }

string Expense_Transaction::get_CategoryID() {
        return categoryID;
    }

double Expense_Transaction::get_Amount() {
        return amount;
    }

string Expense_Transaction::get_WalletID() {
        return walletID;
    }

string Expense_Transaction::get_Description() {
        return description;
    }

void add_Expense(
    DynamicArray<Expense_Transaction>& list_expense,
    DynamicArray<wallet>& list_wallet,
    CategoryManager& categorySection
){
    string date, catID, walletID, desc;
    double amount;

    cout << "\n========== ADD EXPENSE ==========\n";

    // 1. Enter amount
    cout << "Enter amount: ";
    cin >> amount;

    if (cin.fail() || amount <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    // 2. Select category
    cout << "\n========== SELECT CATEGORY ==========\n";
    categorySection.showCategories();

    cout << "Enter category ID: ";
    cin >> catID;

    if (categorySection.findCategoryByID(catID) == -1) {
        cout << "Category not found!\n";
        return;
    }

    // 3. Select wallet
    cout << "\n========== SELECT WALLET ==========\n";
    display_wallet_UI(list_wallet);

    cout << "Enter wallet ID: ";
    cin >> walletID;

    // 4. Input date and description
    cout << "Enter date (DD/MM/YYYY): ";
    cin >> date;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter description: ";
    getline(cin, desc);

    // 5. Find wallet and check balance
    int walletIndex = -1;

    for (int i = 0; i < list_wallet.size(); i++) {
        if (list_wallet[i].get_id() == walletID) {
            walletIndex = i;
            break;
        }
    }

    if (walletIndex == -1) {
        cout << "Wallet not found!\n";
        return;
    }

    if (list_wallet[walletIndex].get_balance() < amount) {
        cout << "Insufficient balance!\n";
        return;
    }

    // 6. Create expense transaction
    Expense_Transaction expense;

    expense.set_Information(
        date, catID, amount, walletID, desc
    );

    // 7. Deduct money from wallet
    if (!list_wallet[walletIndex].deduct_balance(amount)) {
        cout << "Transaction failed!\n";
        return;
    }

    // 8. Save expense transaction
    list_expense.push_back(expense);

    cout << "\nExpense added successfully!\n";
}

