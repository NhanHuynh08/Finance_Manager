#include "include/TransactionManager.h"
// 1:INCOME 0 EXPENSE

bool TransactionManager::addTransaction(const string& wallet_id, const string& category_id, const double& amount,
                                        const Date& date, const string& note, const int type) {
    if( amount<=0  || ( type !=0&& type!=1) || (type==0 && WM.getBalance(wallet_id)-amount<0)){
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
    double lastBalanceW=WM.getBalance(wallet_id);
    double lastBalanceC=CM.getCategoryBalance(category_id,type);
    if(lastBalanceC<-0.5|| lastBalanceW<-0.5) return false;
    double totalW = (type==1) ? lastBalanceW+amount:lastBalanceW-amount;
    double totalC = ( type==1) ? lastBalanceC+amount:lastBalanceC-amount;
    bool ok= WM.updateBalance(wallet_id,totalW)
             &&CM.updateCategory(wallet_id,totalC,type);
    if(ok==false) {
        WM.updateBalance(wallet_id,lastBalanceW);
        CM.updateCategory(wallet_id,lastBalanceC,type);
        return ok;
    }
    return ok;
} 

// Type : 1:INCOME 0:EXPENSE     
bool TransactionManager::getAllTransaction(DynamicArray<Transaction>& Transactions, int type){
    //Transactions.clear();

    for (int i=0; i<TransactionData.size();++i){
        if(TransactionData[i].type==type){
            Transactions.push_back(TransactionData[i]);
        }
    }
    return true;
}