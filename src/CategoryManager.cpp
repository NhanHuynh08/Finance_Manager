#include "include/CategoryManager.h"

CategoryManager::CategoryManager() : count(0), nextID(1) {}

string CategoryManager::generateID(int type) {
    string prefix = (type == 0) ? "INC" : "EXP";   // giả sử 0 = thu, 1 = chi
    string num = to_string(nextID++);              // lấy số hiện tại rồi tăng lên
    while (num.length() < 3) num = "0" + num;      // đệm số 0: 1 -> "001"
    return prefix + num;                           // vd: "EXP003"
}


bool CategoryManager::addCategory(const string& name, const int type) {
    if (count >= 1000) return false;

    string id = generateID(type);
    if (isDuplicateID(id)) return false;   // lớp bảo vệ, phòng khi ID bị trùng

    categories[count] = Category(id, name, type); // mang category luu struct
    count++;
    return true;
}

int CategoryManager::findIndex(const string& name, int type) const {
    for (int i = 0; i < count; i++) {
        if (categories[i].name == name && categories[i].type == type) {
            return i;
        }
    }
    return -1;
}
// Truy index theo ten
    
    // Delete a category
bool CategoryManager::deleteCategory(const string& name, const int type) {
    int index = findIndex(name, type);
    if (index == -1) return false;

    for (int i = index; i < count - 1; i++) {
        categories[i] = categories[i + 1];
    }
    count--;
    return true;
}

    // Edit a category name
bool CategoryManager::renameCategory(const string& oldname,const string& newName, const int type){
    int index = findIndex(oldname, type);
    if (index == -1) return false;
    if (findIndex(newName, type) != -1) return false;
    categories[index].name = newName;
    return true;
}

    // Nguoi dung nhap Nam hoac id (nay private ma nhi), nay co gi sua sau
bool CategoryManager::updateCategory(const string& Name, const double amount, const int type){
    if (findIndex(Name, type) == -1){
        return false;
    }
    int Index = findIndex(Name, type);
    categories[Index].amount = amount;
    return true;

}
    // Query all categories of a specific type (expense or income) up to date (store results in variable categories)
bool CategoryManager::getAllCategories(DynamicArray<Category>& categories_public, const int type, int& size){
    size = 0;
    for (int i = 0; i < count; i++) {
        if (categories[i].type == type) {
            categories_public.push_back(categories[i]);   // đổi tên hàm cho khớp DynamicArray của bạn
            size++;
        }
    }
    return size > 0;
}