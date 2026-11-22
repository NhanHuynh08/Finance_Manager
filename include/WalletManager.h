//Hoang Ngoc Thien
#pragma once
#include <string>
#include "utils.h" 
#include <iostream>
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
    string filePath = "data/wallet.bin";
    bool loadWallets();
    bool saveWallets();
    string generateID();
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
    double getBalance(const string& wallet_id); //-1 if wallet_id doesn't exist
    // Query all wallets
    bool getAllWallet(DynamicArray<Wallet>& wallets);
};
inline WalletManager WM;