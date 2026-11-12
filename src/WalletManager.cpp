#include "include/WalletManager.h" 

string WalletManager::generateID(){ 
    int max_count = 0; 
    for (int i = 0; i < WalletData.size(); i++){ 
        const string& curID = WalletData[i].id; 
        if (curID.rfind("WAL", 0) == 0 && curID.length() > 3){ 
            int num = stoi(curID.substr(3)); 
            if (num > max_count){ 
                max_count = num; 
            }
        }
    }
    return "WAL" + to_string(max_count + 1); 
}

bool WalletManager::addWallet(const string& name, const double balance){ 
    if (name.empty()){ 
        return false; 
    }
    Wallet w; 
    w.name = name; 
    w.id = this->generateID(); 
    w.balance = balance; 
    WalletData.push_back(w); 
    // save or not 
    return true; 
}

// Delete a wallet
bool WalletManager::deleteWallet(const string& id){ 
    for (int i = 0; i < WalletData.size(); i++){ 
        if (id == WalletData[i].id){ 
            WalletData.removeAt(i); 
            // save data or not 
            return true; 
        }
    }
    return false; 
}

// this.renameWallet() --> having pointer --> using this->generateID() = generateID()
bool WalletManager::renameWallet(const string& id, const string& newName){ // add a WalletManager this having WalletData 
    for (int i = 0; i < WalletData.size(); i++){ 
        if (id == WalletData[i].id){ 
            WalletData[i].name = newName; 
            // save data or not 
            return true; 
        }
    }
    return false; 
}

bool WalletManager::updateBalance(const string& wallet_id, const double amount){ 
    for (int i = 0; i < WalletData.size(); i++){ 
        if (wallet_id == WalletData[i].id){ 
            // balance > 0; 
            WalletData[i].balance = amount; 
            return true; 
        }
    }
    return false; 
}

// Query all wallets
bool WalletManager::getAllWallet(DynamicArray<Wallet>& wallets, int& size){ 
    
}