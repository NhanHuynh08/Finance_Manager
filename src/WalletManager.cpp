#include "include/WalletManager.h" 

bool WalletManager::loadWallets(){  // picking information from data/Wallet.bin 
    // loading with parameter filePath, and DynamicArray<Wallet> WalletData

}

bool WalletManager::saveWallets(){ // saving information to data/Wallet.bon (we will truncate <overwrite>)
    // saving with parameter filePath, and DynamicArray<Wallet> WalletData

}

WalletManager::WalletManager(const string& Path){ // load data to WalletManager each call (run app)
    filePath = Path; 
    bool load = loadWallets(); 
    if (!load || WalletData.size() == 0){ 
        addWallet("Ngân hàng MB Bank", 1000000);  // auto having this pointer 
        addWallet("Ví cá nhân", 500000);  
        saveWallets();
    }
}

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
    // save data 
    saveWallets();  // auto having this (WalletManager) pointer
    return true; 
}

// Delete a wallet
bool WalletManager::deleteWallet(const string& id){ 
    for (int i = 0; i < WalletData.size(); i++){ 
        if (id == WalletData[i].id){ 
            WalletData.removeAt(i); 
            saveWallets(); 
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
            saveWallets(); 
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
            saveWallets(); 
            return true; 
        }
    }
    return false; 
}

// Query all wallets
bool WalletManager::getAllWallet(DynamicArray<Wallet>& wallets, int& size){ 
    
}