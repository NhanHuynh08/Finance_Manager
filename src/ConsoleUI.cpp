#include "include/ConsoleUI.h"
#include <iostream>

void printTitle(std::string& title) {
    int width = std::max(100, (int)title.length());
    std::cout << string(width, '=') << '\n';
    std::cout << title << '\n';
    std::cout << string(width, '=') << '\n';
    return;
}
void printNavigationMenu(DynamicArray<std::string>& choices) {
    for (int i=0; i<choices.size(); i++) {
        cout << "[" << i+1 << "] " << choices[i] << '\n';
    }
    cout << "[0] EXIT" << '\n';
    return;
}
void ConsoleUI::displayDashBoard() {
    using namespace std;
    string title = "DASHBOARD"; int width = max(100, (int)title.length());
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
    cout << "Total balance: " << total_balance << '\n';
    cout << "Wallet list: " << '\n';
    for (int i; i<wallet_list.size(); i++) {
        cout << "   + " << wallet_list[i].name << ": " << wallet_list[i].balance << " VND" << '\n';
    }
    cout << string(width, '-') << '\n';
    printNavigationMenu(choices);
    cout << string(width, '=') << '\n';
    cout << "Type your choice here: ";
    return;
};