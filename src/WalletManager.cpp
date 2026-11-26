#include "include/WalletManager.h" 

void Wallet::saveBinary(ofstream& Out) const { 
    BinaryIO::write(Out, name); 
    BinaryIO::write(Out, balance); 
    BinaryIO::write(Out, id); 
} 

bool Wallet::loadBinary(ifstream& In){ // auto go into Wallet
    return (BinaryIO::read(In, name) && BinaryIO::read(In, balance) && BinaryIO::read(In,id)); 
}

bool WalletManager::loadWallets(){  // picking information from data/Wallet.bin 
    // loading with parameter filePath, and DynamicArray<Wallet> WalletData
    ifstream Load(filePath, ios::binary); 
    if (!Load) return false; 
    return BinaryIO::read(Load, WalletData); 
}

bool WalletManager::saveWallets(){ // saving information to data/Wallet.bon (we will truncate <overwrite>)
    // saving with parameter filePath, and DynamicArray<Wallet> WalletData
    ofstream Save(filePath, ios::binary); 
    if (!Save) return false; 
    BinaryIO::write(Save, WalletData); 
    return true;
}

WalletManager::WalletManager() { // load data to WalletManager each call (run app)
    bool load = loadWallets(); 
    if (!load || WalletData.size() == 0){ 
        addWallet("MB Bank", 1000000);  // auto having this pointer 
        addWallet("Physical wallet", 500000);  
    }
}

WalletManager::~WalletManager(){ 
    saveWallets(); 
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
    return true; 
}

// Delete a wallet
bool WalletManager::deleteWallet(const string& id){ 
    for (int i = 0; i < WalletData.size(); i++){ 
        if (id == WalletData[i].id){ 
            WalletData.removeAt(i);  
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

double WalletManager::getBalance(const string& wallet_id) {
    double balance{-1};
    for (int i = 0; i < WalletData.size(); i++){ 
        if (wallet_id == WalletData[i].id){ 
            // balance > 0; 
            balance = WalletData[i].balance;
            break;
        }
    }
    return balance;
}

// Query all wallets
bool WalletManager::getAllWallet(DynamicArray<Wallet>& wallets){ 
    wallets.clear(); 
    for (int i = 0; i < WalletData.size(); i++){ 
        wallets.push_back(WalletData[i]); 
    }
    return true;
}