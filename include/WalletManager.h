//Hoang Ngoc Thien
#pragma once
#include <string>
#include "utils.h" 
using namespace std; 

struct Wallet {
    string id; 
    string name; 
    double balance = 0.0; 
};

class WalletManager { 
private:
    DynamicArray<Wallet> walletData;
public:
    WalletManager();

    // Add a new wallet
    bool addWallet(string& name, double balance);
    // Delete a wallet
    bool deleteWallet(string& id);
    // Edit a wallet name
    bool editWallet(string& id, string& newName);

    //Query all wallets
    bool getAllWallet(DynamicArray<Wallet>& wallets, int& size);
}; 


