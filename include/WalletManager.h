//Hoang Ngoc Thien
#pragma once
#include <string>
#include "utils.h" 
using namespace std; 

class Wallet {
public:
    string name; 
    double balance = 0.0; 
    string id;
};
class WalletManager { 
private:
    DynamicArray<Wallet> WalletData;
    //bool accessData();
public:
    WalletManager();

    // Add a new wallet
    bool addWallet(const string& name, const double balance);
    // Delete a wallet
    bool deleteWallet(const string& id);
    // Edit a wallet name
    bool renameWallet(const string& id, const string& newName);

    // Update balance by amount
    bool updateBalance(const string& wallet_id, const double amount);

    // Query all wallets
    bool getAllWallet(DynamicArray<Wallet>& wallets, int& size);
}; 


