Tran Tra Khoi Nguyen

int displayDashBoard();
- Menu chính, hiển thị danh sách ví, tổng tiền
- Navigate route:
    <1> walletManagementMenu
    <2> transactionManagementMenu 
    <3> expenseCategoryManagementMenu 
    <4> incomeSourceManagementMenu
    <0> Exit


int transactionManagementMenu(int type);
- Thực hiện giao dịch, điền thông tin theo route như comment
- Navigate route:
    <1> Thêm giao dịch
        <1> return
        <2> Dashboard
        <0> Exit
    <2> Truy vấn lịch sử giao dịch 
        <1> return
        <2> Dashboard
        <0> Exit
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



Note:
    - printTotalBalance
    - getAllWallet &size parameter is redundant
