#include "include/TransactionManager.h"
// 1:INCOME 0 EXPENSE

void Month_Transaction::saveBinary(ofstream& Out) const { 
    BinaryIO::write(Out, begin); 
    BinaryIO::write(Out, end); 
    BinaryIO::write(Out, wallet_id); 
    BinaryIO::write(Out, category_id); 
    BinaryIO::write(Out, amount); 
    BinaryIO::write(Out, note); 
    BinaryIO::write(Out, type); 
    BinaryIO::write(Out, nextday); 
} 

bool Month_Transaction::loadBinary(ifstream& In){ // auto go into Wallet
    return (
        BinaryIO::read(In, begin) && 
        BinaryIO::read(In, end) && 
        BinaryIO::read(In, wallet_id) && 
        BinaryIO::read(In, category_id) && 
        BinaryIO::read(In, amount) && 
        BinaryIO::read(In, note) && 
        BinaryIO::read(In, type) && 
        BinaryIO::read(In, nextday)
    ); 
}

bool Month_Transaction::check_recurring(){ 
    bool avaiable = Date::compared(nextday, end) < 1;
    if (!avaiable) return false;  
    Date today = Date::get_current_date(); 
    avaiable = Date::compared(nextday, today); 
    nextday.One_more_month(begin.day); 
    return avaiable; 
}

void Transaction::saveBinary(ofstream& Out) const { 
    BinaryIO::write(Out, id); 
    BinaryIO::write(Out, wallet_id); 
    BinaryIO::write(Out, category_id); 
    BinaryIO::write(Out, amount); 
    BinaryIO::write(Out, date); // will write about save class of Date in utils.h
    BinaryIO::write(Out, note); 
    BinaryIO::write(Out, type); 
} 

bool Transaction::loadBinary(ifstream& In){ // auto go into Wallet
    return (
        BinaryIO::read(In, id) && 
        BinaryIO::read(In, wallet_id) && 
        BinaryIO::read(In, category_id) && 
        BinaryIO::read(In, amount) && 
        BinaryIO::read(In, date) && 
        BinaryIO::read(In, note) && 
        BinaryIO::read(In, type)
    ); 
}

bool TransactionManager::loadTransactionManager(){  // picking information from data/Wallet.bin 
    // loading with parameter filePath, and DynamicArray<Wallet> WalletData
    ifstream Load(filePath, ios::binary); 
    if (!Load) return false; 
    return (BinaryIO::read(Load, TransactionData) && BinaryIO::read(Load, RecurringData)); 
}

bool TransactionManager::saveTransactionManager(){ // saving information to data/Wallet.bon (we will truncate <overwrite>)
    // saving with parameter filePath, and DynamicArray<Wallet> WalletData
    ofstream Save(filePath, ios::binary); 
    if (!Save) return false; 
    BinaryIO::write(Save, TransactionData); 
    BinaryIO::write(Save, RecurringData); 
    return true;
}

TransactionManager::TransactionManager() { // load data to WalletManager each call (run app)
    loadTransactionManager(); 
    // check whether it could add or not 
    for (int i = 0; i < RecurringData.size(); ++i){ 
        Month_Transaction month_transaction = RecurringData[i]; 
        if (month_transaction.check_recurring()){ 
            addTransaction(
                month_transaction.wallet_id, month_transaction.category_id, month_transaction.amount, 
                month_transaction.nextday, month_transaction.note, month_transaction.type
            ); 
        }
    }
}

TransactionManager::~TransactionManager(){ 
    saveTransactionManager(); 
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