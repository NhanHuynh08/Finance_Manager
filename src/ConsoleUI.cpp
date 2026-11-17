#include "include/ConsoleUI.h"
#include <iostream>
#include "include/utils.h"

//private:
void printTitle(std::string& title) {
    std::cout << string(width, '=') << '\n';
    std::cout << title << '\n';
    std::cout << string(width, '=') << '\n';
    return;
}
void printWalletList(DynamicArray<Wallet>& wallet_list) {
    std::cout << "Wallet list: " << '\n';
    for (int i=0; i<wallet_list.size(); i++) {
        std::cout << "   " << i+1 << ". " << wallet_list[i].name << ": " << wallet_list[i].balance << " VND" << '\n';
    }
    return;
}
void printCategoryList(DynamicArray<Category>& category_list) {
    using namespace std;
    cout << "Category list:" << '\n';
    for (int i=0; i<category_list.size(); i++) {
        std::cout << "   " << i+1 << ". " << category_list[i].name << ": " << category_list[i].amount << '\n';
    }
    return;
}
int userChoice(DynamicArray<std::string>& choices) {
    for (int i=0; i<choices.size(); i++) {
        cout << "[" << i+1 << "] " << choices[i] << '\n';
    }
    cout << "[0] EXIT" << '\n';
    std::cout << std::string(width, '=') << '\n';
    std::cout << "Type your choice here: ";
    int user_choice{};
    while (true) {
        std::cin >> user_choice;
        if (user_choice <= choices.size() && user_choice >= 0) {
            return user_choice;
        }
        else {
            std::cout << "Invalid choice, please retry: ";
        }
    }
    return;
}
// transaction child:
int addTransaction(int type) {
    //get and process data
    TransactionManager TransactionManager;
    DynamicArray<Wallet> wallet_list; int n{}; int choice{};
    WalletManager WalletManager;
    WalletManager.getAllWallet(wallet_list, n);
    CategoryManager CategoryManager;
    DynamicArray<Category> category_list;
    CategoryManager.getAllCategories(category_list, type, n);
    DynamicArray<string> choices;
    choices.push_back("Return to transaction menu");
    choices.push_back("Return to dashboard");
    //screen
    printWalletList(wallet_list);
    std::cout << std::string(width, '-') << '\n';
    std::cout << "Select a wallet: "; 
    while (true) {
        if (std::cin >> choice && choice<=wallet_list.size() && choice>0) {
            break;
        }
        else std::cout << "Invalid input, please retry: " << '\n';
    }
    std::string wallet_id = wallet_list[choice-1].id;
    printCategoryList(category_list);
    std::cout << std::string(width, '-') << '\n';
    std::cout << "Select a category: "; 
    while (true) {
        if (std::cin >> choice && choice<=wallet_list.size() && choice>0) {
            break;
        }
        else std::cout << "Invalid input, please retry: " << '\n';
    }
    std::string category_id = category_list[choice-1].id;
    double amount{}; Date date; std::string note{}; 
    std::cout << "Amount: "; std::cin >> amount;
    std::cout << "Date (dd mm yyyy): "; std::cin >> date.day >> date.month >> date.year;
    std::cout << "Transaction note: "; getline(cin, note);
    if (TransactionManager.addTransaction(wallet_id, category_id, amount, date, note, type)) {
        std::cout << "Added transaction successfully!" << '\n';
    }
    else {
        std::cout << "Transaction failed, please retry." << '\n';
    }
    return userChoice(choices);
}
int transactionHistory(int type) {
    TransactionManager TransactionManager;
    WalletManager WalletManager;
    DynamicArray<Transaction> transaction_list; int n{};
    TransactionManager.getAllTransaction(transaction_list, type, n);
    DynamicArray<string> choices;
    choices.push_back("Return to transaction menu");
    choices.push_back("Return to dashboard");

    for (int i=0; i<transaction_list.size(); i++) {
        transaction_list[i].date.displayDate(); 
        std::cout << ": " << transaction_list[i].amount << '\n'
                  << "Note: " << transaction_list[i].note << '\n';
    }
    return userChoice(choices);
}
// Wallet features
int newWallet() {
    DynamicArray<std::string> choices;
    choices.push_back("Return to wallet menu");
    choices.push_back("Return to dashboard");
    using namespace std;
    WalletManager WalletManager;
    std::string wallet_name{};
    double balance{};
    cout << "Enter new wallet name: ";
    getline(cin, wallet_name);
    cout << "Enter wallet balance: ";
    cin >> balance;
    WalletManager.addWallet(wallet_name, balance);
    return userChoice(choices);
}
int deleteWallet(DynamicArray<Wallet>& wallet_list) {
    DynamicArray<std::string> choices;
    choices.push_back("Return to wallet menu");
    choices.push_back("Return to dashboard");
    using namespace std;
    WalletManager WalletManager;
    int choice{};
    cout << "Enter wallet index to delete: ";
    while (true) {
        cin >> choice;
        if (choice <= wallet_list.size() && choice > 0) {
            WalletManager.deleteWallet(wallet_list[choice-1].id);
            break;
        }
        else {
            cout << "Invalid index, please retry: ";
        }
    }
    return userChoice(choices);
}
int renameWallet(DynamicArray<Wallet>& wallet_list) {
    DynamicArray<std::string> choices;
    choices.push_back("Return to wallet menu");
    choices.push_back("Return to dashboard");
    using namespace std;
    WalletManager WalletManager;
    int choice{};
    cout << "Enter wallet index to rename: ";
    while (true) {
        cin >> choice;
        if (choice <= wallet_list.size() && choice > 0) {
            std::string new_name{};
            cout << "Rename " << wallet_list[choice-1].name << " to: ";
            getline(cin, new_name);
            WalletManager.renameWallet(wallet_list[choice-1].id, new_name);
            break;
        }
        else {
            cout << "Invalid index, please retry: ";
        }
    }
    return userChoice(choices);
}
// Category features
int newCategory(int type) {
    DynamicArray<std::string> choices;
    choices.push_back("Return to category menu");
    choices.push_back("Return to dashboard");
    using namespace std;
    CategoryManager CategoryManager;
    std::string category_name{};
    std::string category_type = (type==1) ? "income source" : "expense category";
    cout << "Enter new " << category_type << " name: ";
    getline(cin, category_name);
    CategoryManager.addCategory(category_name, type);
    return userChoice(choices);
}
int deleteCategory(DynamicArray<Category>& category_list, int type) {
    DynamicArray<std::string> choices;
    choices.push_back("Return to category menu");
    choices.push_back("Return to dashboard");
    using namespace std;
    CategoryManager CategoryManager;
    int choice{};
    std::string category_type = (type==1) ? "income source" : "expense category";
    cout << "Enter " << category_type << " index to delete: ";
    while (true) {
        cin >> choice;
        if (choice <= category_list.size() && choice > 0) {
            CategoryManager.deleteCategory(category_list[choice-1].id, type);
            break;
        }
        else {
            cout << "Invalid index, please retry: ";
        }
    }
    return userChoice(choices);
}
int renameWallet(DynamicArray<Category>& category_list, int type) {
    DynamicArray<std::string> choices;
    choices.push_back("Return to category menu");
    choices.push_back("Return to dashboard");
    using namespace std;
    CategoryManager CategoryManager;
    int choice{};
    std::string category_type = (type==1) ? "income source" : "expense category";
    cout << "Enter " << category_type << " index to rename: ";
    while (true) {
        cin >> choice;
        if (choice <= category_list.size() && choice > 0) {
            std::string new_name;
            cout << "Enter " << category_list[choice-1].name << " new name: ";
            getline(cin, new_name);
            CategoryManager.renameCategory(category_list[choice-1].id, new_name, type);
            break;
        }
        else {
            cout << "Invalid index, please retry: ";
        }
    }
    return userChoice(choices);
}
// public:
int ConsoleUI::displayDashBoard() {
    std::string title = "DASHBOARD";
    DynamicArray<Wallet> wallet_list; int n{}; int total_balance{};
    WalletManager WalletManager;
    WalletManager.getAllWallet(wallet_list, n);
    for (int i=0; i<wallet_list.size(); i++) {
        total_balance+=wallet_list[i].balance;
    }
    DynamicArray<string> choices;
    choices.push_back("Wallet Management");
    choices.push_back("Transaction Management");
    choices.push_back("Expense Category Management");
    choices.push_back("Income Source Management");

    printTitle(title);
    std::cout << "Total balance: " << total_balance << '\n';
    printWalletList(wallet_list);
    std::cout << std::string(width, '-') << '\n';
    return userChoice(choices);
}

int ConsoleUI::transactionManagementMenu(int type) {
    //get and process data
    std::string transaction_type = (type==1) ? "Income" : "Expense";
    std::string title = (type==1) ? "INCOME MANAGEMENT MENU" : "EXPENSE MANAGEMENT MENU";
    DynamicArray<Wallet> wallet_list; int n{}; int total_balance{};
    WalletManager WalletManager;
    WalletManager.getAllWallet(wallet_list, n);
    for (int i=0; i<wallet_list.size(); i++) {
        total_balance+=wallet_list[i].balance;
    }
    DynamicArray<string> choices;
    choices.push_back("Add a new " + transaction_type);
    choices.push_back(transaction_type +  " history");
    choices.push_back("Return to dashboard");
    //screen
    printTitle(title);
    std::cout << "Total balance: " << total_balance << '\n';
    printWalletList(wallet_list);
    std::cout << std::string(width, '-') << '\n';
    return userChoice(choices);
}
int ConsoleUI::walletManagementMenu() {
    //get and process data
    std::string title = "WALLET MANAGEMENT MENU";
    DynamicArray<Wallet> wallet_list; int n{}; int total_balance{};
    WalletManager WalletManager;
    WalletManager.getAllWallet(wallet_list, n);
    for (int i=0; i<wallet_list.size(); i++) {
        total_balance+=wallet_list[i].balance;
    }
    DynamicArray<string> choices;
    choices.push_back("Add a new wallet");
    choices.push_back("Delete a wallet");
    choices.push_back("Rename a wallet");
    choices.push_back("Return to dashboard");
    //screen
    printTitle(title);
    std::cout << "Total balance: " << total_balance << '\n';
    printWalletList(wallet_list);
    std::cout << std::string(width, '-') << '\n';
    return userChoice(choices);
}
int ConsoleUI::categoryManagementMenu(int type) {
    //get and process data
    std::string title = (type==1) ? "INCOME SOURCE MANAGEMENT MENU" : "EXPENSE CATEGORY MANAGEMENT MENU";
    DynamicArray<Category> category_list; int n{};
    CategoryManager CategoryManager;
    CategoryManager.getAllCategories(category_list, type, n);
    DynamicArray<string> choices;
    std::string category_type = (type==1) ? "income source" : "expense source";
    choices.push_back("Add a new " + category_type);
    choices.push_back("Delete a " + category_type);
    choices.push_back("Rename a " + category_type);
    choices.push_back("Return to dashboard");
    //screen
    printTitle(title);
    printCategoryList(category_list);
    std::cout << std::string(width, '-') << '\n';
    return userChoice(choices);
}