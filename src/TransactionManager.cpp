#include "include/TransactionManager.h"
// 1:INCOME 0 EXPENSE

bool TransactionManager::addTransaction(string& wallet_id, string& category_id, double& amount,
                                          Date& date, string& note, int type){
    if( amount<=0  || ( type !=0&& type!=1) || (type==0 && getBalance(wallet_id)-amount<0)){
        return false;
    }
    Transaction ts;
    if(type==1){
        ts.id="IN"+to_string(inCount);
        inCount++;
    }
    else{
        ts.id="EX"+to_string(exCount);
        exCount++;
    }
    ts.wallet_id=wallet_id;
    ts.category_id=category_id;
    ts.amount=amount;
    ts.date=date;
    ts.note=note;
    ts.type=type;

    TransactionData.push_back(ts);
    amount= (type==1)?(getBalance(wallet_id)+amount):(getBalance(wallet_id)-amount);
    return updateBalance (wallet_id,amount);
} 

// Type : 1:INCOME 0:EXPENSE     
bool TransactionManager::getAllTransaction(DynamicArray<Transaction>& Transactions, int type, int& size){
    Transactions.clear();

    for (int i=0; i<TransactionData.size();++i){
        if(TransactionData[i].type==type){
            Transactions.push_back(TransactionData[i]);
        }
    }
    return true;
}