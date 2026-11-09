Tran Tra Khoi Nguyen

static void displayDashBoard();
- Menu chính, hiển thị danh sách ví, tổng tiền
- Navigate route:
    <1> walletManagementMenu
    <2> transactionManagementMenu -> chọn type
    <3> categoryManagementMenu -> chọn type
    <0> Exit

// Wallet -> Category -> Transaction information -> Transaction.cpp
static void transactionManagementMenu(int type);
- Thực hiện giao dịch, điền thông tin theo route như comment
- Navigate route:
    <1> Thêm giao dịch
    <2> Truy vấn lịch sử giao dịch
    <3> Dashboard
    <0> Exit

// Edit wallet name, delete wallet, add new wallet
static void walletManagementMenu();
- Hiển thị menu
- Navigate route:
    <1> Thêm ví
    <2> Xóa ví
    <3> Đổi tên ví
    <4> Dashboard
    <0> Exit

// Edit category name, delete category, add new category
static void categoryManagementMenu(int type);
- Hiển thị category, số tiền
- Navigate route:
    <1> Thêm category
    <2> Xóa category
    <3> Đổi tên category
    <4> Dashboard
    <0> Exit