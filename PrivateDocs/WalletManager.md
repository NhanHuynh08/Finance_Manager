Hoang Ngoc Thien
Hàm khởi tạo constructor (edit arguments nếu cần)
Thêm sẵn 2 wallet mặc định có tên và số dư:
    - Ngân hàng MB Bank: 1000000
    - Ví cá nhân: 500000

**TRẢ TRUE NẾU THÀNH CÔNG, FALSE NẾU THẤT BẠI**
bool addWallet(string& name, double balance);
- Thêm wallet vào database

bool deleteWallet(string& id);
- Xóa wallet <id>

bool renameWallet(string& id, string& newName);
- Đổi tên wallet<id> thành newName

bool updateBalance(string& id, double amount);
- Cập nhật số dư của wallet <id> **bằng amount**
E.g. Sau khi gọi updateBalance("1011", "20000") thì wallet có id 1011 phải có số dư bằng 20000

bool getAllWallet(DynamicArray<Wallet>& wallets, int& size);
- Lấy tất cả wallets trong database ghi vào <wallets>, cập nhật size.