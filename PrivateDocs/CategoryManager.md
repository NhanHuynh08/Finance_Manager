Nguyen Ngoc Quynh Thi
Constructor function (edit arguments nếu cần)
- Tạo sẵn 6 category mặc định
- Tạo sẵn 2 income source mặc định

**TRẢ TRUE NẾU THÀNH CÔNG, FALSE NẾU THẤT BẠI**
bool addCategory(string& name, int type);
Validate <type>, amount mặc định lúc thêm = 0
Thêm Category có tên là <name>, gán <id> vào database:
    type 0: ExpenseCategory
    type 1: IncomeSource

bool deleteCategory(string& id, int type);
    xóa category có id là <id>, <type>
    nếu không tồn tại trả false

bool renameCategory(string& id, string& newName, int type);
    đổi tên category <id><type> bằng <newName>
    nếu không tồn tại trả false

bool updateCategory(string& id, double amount, int type);
    cập nhật tiền của category <id><type>

bool getAllCategories(DynamicArray<Category>& categories, int type, int& size);
    đọc hết tất cả Categories <type> vào categories
    true nếu thành công 100%
    false nếu thất bại
