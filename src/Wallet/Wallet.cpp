# include "wallet.h" 
# include <iostream> 
#include <limits> 

// declare new wallet 
wallet::wallet(){ 
    id = 'UNKNOWN'; 
    name = "UNKNOWN"; 
}

wallet::wallet(const string& id, const string& name, const double& balance){ 
    this->id = id; 
    this->name = name; 
    this->balance = balance; 
}

// get balance of wallet 
double wallet::get_balance() const { return balance;} 

// get name of wallet 
string wallet::get_name() const {return name;}

// get id of wallet 
string wallet::get_id() const {return id;}

// set name of wallet 
void wallet::set_name(string& new_name){ name = new_name; }

// use to cout << wallet (get_balance, get_name)
ostream& operator << (ostream& cout, wallet x){  
    cout << "- " << x.get_name() << ": " << x.get_balance(); 
}

// add new wallet into list_wallet
void add_wallet(string& name, double& balance, DynamicArray<wallet>& list_wallet){ 
    cout << "Tên ví bạn muốn thêm: "; cin >> name; 
    cout << "Số tiền ban đầu của ví: "; cin >> balance;        
    string id_wallet = "WAL" + to_string(list_wallet.size() + 1); 
    wallet new_wallet(id_wallet, name, balance); 
    list_wallet.push_back(new_wallet); 
}

// display list of wallet on dashboard  (with << only cout name and balance) (when income transaction needs to inputs wallet)
void display_wallet_UI(DynamicArray<wallet>& list_wallet){
    for (wallet& x : list_wallet){ 
        cout << x << endl; 
    }
}

// display wallet management (include id, name, balance) 
void display_wallet_mangement_to_edit(DynamicArray<wallet>& list_wallet){ 
    cout << "--- QUẢN LÝ VÍ TIỀN ---\n"; 
    for (int i = 0; i < list_wallet.size(); i++){ 
        cout << '[' + (i+1) << ']'
            << " Mã ví: " << list_wallet[i].get_id() 
            << ", Tên: " << list_wallet[i].get_name() 
            << ", Số dư: " << list_wallet[i].get_balance(); 
        cout << "\n"; 
    }
    cout << "Nhập STT ví cần sửa/xóa (hoặc 0 để quay lại): "; 
}

// edit name of wallet 
void edit_wallet(DynamicArray<wallet>& list_wallet){ 
    if (list_wallet.size() == 0){ 
        cout << "Danh sách ví trống, hãy tạo ví mới của bạn\n";
        return; 
    }
    display_wallet_mangement_to_edit(list_wallet); 
    int stt = -1; cin >> stt;
    if (stt == 0) return; 
    while(stt > list_wallet.size()){ 
        cout << "Số thứ tự không thỏa mãn, yêu cầu nhập lại: "; 
        cin >> stt; 
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    cout << "Tên mới: "; 
    string new_name; 
    getline(cin, new_name);
    list_wallet[stt - 1].set_name(new_name); 
    cout << "Đã cập nhật thành công. \n";
    return; 
}
