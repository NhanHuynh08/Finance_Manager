#include "include/TransactionManager.h"
bool TransactionManager::addTransaction(string& wallet_id, string& category_id, double& amount,
                                          Date& date, string& note, int type){
    if( amount<=0  || ( type !=0&& type!=1)){
        return false;
    }

    Transaction ts;
    string prefix =( type ==1) ? "IN":"EX";
    string postfix= to_string(transactionData.size()+1);
    ts.id= prefix+postfix;
    ts.wallet_id=wallet_id;
    ts.category_id=category_id;
    ts.amount=amount;
    //ts.date=data;
    ts.note=note;
    ts.type=type;
    transactionData.push_back(ts);
    return 1;
} 

// Type : 1:INCOME 0:EXPENSE -1:ALL     
bool TransactionManager::getAllTransaction(DynamicArray<Transaction>& transactions, int type, int& size){
    transactions.clear();

    for (int i=0; i<transactionData.size();++i){
        if(type==-1 || transactionData[i].type==type){
            transactions.push_back(transactionData[i]);
        }
    }
    
    size=transactions.size();
    return true;
}