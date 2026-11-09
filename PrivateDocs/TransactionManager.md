Huynh Nghia Nhan
Hàm constructor (thay đổi arguments nếu cần)

**TRẢ TRUE NẾU THÀNH CÔNG, FALSE NẾU THẤT BẠI**
bool addTransaction(string& wallet_id, string& category_id, double& amount, Date& date, string& note, int type);
- Thêm giao dịch mới vào database:
    - Kiểm tra số tiền còn lại trong ví
    - Tính số tiền sau giao dịch
    - Gọi hàm updateBalance để cập nhật số dư
    - Gọi hàm updateCategory để cập nhật số dư
    - Lưu transaction vào database


bool getAllTransaction(DynamicArray<Transaction>& transactions, int type, int& size);
- Ghi tất cả transaction <type> vào <transactions> và cập nhật size