//Hoang Ngoc Thien
#pragma once
#include <string>
#include "utils.h" 
#include "BinaryIO.h"
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
    string filePath; 
    //bool accessData();
    bool saveWallets(); // auto having this pointer 
    bool loadWallets(); 
    string generateID(); // auto having pointer this 
public:
    WalletManager(const string& Path = "./data/Wallet.bin"); // having WalletDate (auto having pointer this)

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


