#include "include/TransactionManager.h"
// 1:INCOME 0 EXPENSE

void Transaction::saveBinary(ofstream& Out) const { 
    BinaryIO::write(Out, id); 
    BinaryIO::write(Out, wallet_id); 
    BinaryIO::write(Out, category_id); 
    BinaryIO::write(Out, amount); 
    BinaryIO::write(Out, date); // will write about save class of Date in utils.h
    BinaryIO::write(Out, note); 
} 

bool Transaction::loadBinary(ifstream& In){ // auto go into Wallet
    return (
        BinaryIO::read(In, id) && 
        BinaryIO::read(In, wallet_id) && 
        BinaryIO::read(In, category_id) && 
        BinaryIO::read(In, amount) && 
        BinaryIO::read(In, date) && 
        BinaryIO::read(In, note)
    ); 
}

bool TransactionManager::loadTransaction(){  // picking information from data/Wallet.bin 
    // loading with parameter filePath, and DynamicArray<Wallet> WalletData
    ifstream Load(filePath, ios::binary); 
    if (!Load) return false; 
    return BinaryIO::read(Load, TransactionData); 
}

bool TransactionManager::saveTransaction(){ // saving information to data/Wallet.bon (we will truncate <overwrite>)
    // saving with parameter filePath, and DynamicArray<Wallet> WalletData
    ofstream Save(filePath, ios::binary); 
    if (!Save) return false; 
    BinaryIO::write(Save, TransactionData); 
    return true;
}

TransactionManager::TransactionManager() { // load data to WalletManager each call (run app)
    loadTransaction(); 
}

TransactionManager::~TransactionManager(){ 
    saveTransaction(); 
}


bool TransactionManager::addTransaction(const string& wallet_id, const string& category_id, const double& amount,
                                        const Date& date, const string& note, const int type) {
    if (amount <= 0 || ( type != 0 && type != 1) || (type == 0 && WM.getBalance(wallet_id) - amount < 0)){
        return false;
    }
    Transaction ts;
    if(type==1){
        ts.id="IN" + to_string(inCount);
        inCount++;
    }
    else{
        ts.id="EX" + to_string(exCount);
        exCount++;
    }
    ts.wallet_id = wallet_id;
    ts.category_id = category_id;
    ts.amount = amount;
    ts.date = date;
    ts.note = note;
    ts.type = type;
    TransactionData.push_back(ts);

    double total= (type==1)?(WM.getBalance(wallet_id) + amount):(WM.getBalance(wallet_id) - amount);
    
    return WM.updateBalance(wallet_id,total)
          &&CM.updateCategory(category_id,amount,type);
} 

// Type : 1:INCOME 0:EXPENSE     
bool TransactionManager::getAllTransaction(DynamicArray<Transaction>& Transactions, int type){
    //Transactions.clear();

    for (int i = 0; i < TransactionData.size(); ++i){
        if(TransactionData[i].type == type){
            Transactions.push_back(TransactionData[i]);
        }
    }
    return true;
}