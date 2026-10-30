#pragma once 
#include <string>
#include "DynamicArray.h" 
using namespace std; 


class wallet{ 
private:
    string id; 
    string name; 
    double balance = 0.0; 
public:
    wallet(); 
    wallet(const string& id, const string& name, const double& balance); 

    // return name of wallet 
    string get_name() const; 
    
    // return balance of wallet 
    double get_balance() const; 

    // return id of wallet 
    string get_id() const; 

    void wallet::set_name(string& new_name);

    friend ostream& operator << (ostream& cout, wallet x); 
}; 
// add a new wallet (input only name and balance) to list_wallet
void add_wallet(string& name, double& balance, DynamicArray<wallet>& list_wallet); 

// display list of wallets on dashboard (in page 4 about wallet balances)
void display_wallet_UI(DynamicArray<wallet>& list_wallet); 

// 
void delete_wallet(DynamicArray<wallet>&, string& name);