#include "include/CategoryManager.h"
#include "include/utils.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
=======
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121

CategoryManager::CategoryManager() : nextID(1) {}

string CategoryManager::generateID(int type) {
    string prefix = (type == 0) ?  "EXP" : "INC" ;   // giả sử 0 = thu, 1 = chi
    string num = to_string(nextID++);              // lấy số hiện tại rồi tăng lên
    while (num.length() < 3) num = "0" + num;      // đệm số 0: 1 -> "001"
    return prefix + num;                           // vd: "EXP003"
}

<<<<<<< HEAD
<<<<<<< HEAD
bool CategoryManager::isDuplicateID(const string& id, int type) {
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    for (int i = 0; i < list.size(); i++){
        if (list[i].id == id) return true;
    }
    return false;
}

int CategoryManager::findIndex(const string& id, int type) {
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    for (int i = 0; i < list.size(); i++) {
            if (list[i].id == id) {
                return i;
            }
        }
    return -1;
}

bool CategoryManager::addCategory(const string& name, const int type) {
    string id = generateID(type);
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    if (isDuplicateID(id, type)) return false;   
    list.push_back(Category(id, name, type));
    
    return true;
}

=======
bool CategoryManager::isDuplicateID(const string& id) {
    for (int i = 0; i < categories.size(); i++){
        if (categories[i].id == id) return true;
    }
    return false;
}

=======
bool CategoryManager::isDuplicateID(const string& id) {
    for (int i = 0; i < categories.size(); i++){
        if (categories[i].id == id) return true;
    }
    return false;
}

>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
int CategoryManager::findIndex(const string& id, int type) {
    for (int i = 0; i < categories.size(); i++) {
        if (categories[i].id == id) { // Sao bao loi o day v 
            return i;
        }
    }
    return -1;
}

bool CategoryManager::addCategory(const string& name, const int type) {
    string id = generateID(type);
    if (isDuplicateID(id)) return false;   // lớp bảo vệ, phòng khi ID bị trùng

    categories.push_back(Category(id, name, type)); // mang category luu struct
    return true;
}

<<<<<<< HEAD
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
=======
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121


bool CategoryManager::deleteCategory(const string& id, const int type) {
    int index = findIndex(id, type);
    if (index == -1) return false;

<<<<<<< HEAD
<<<<<<< HEAD
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    list.removeAt(index);

=======
=======
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
    for (int i = index; i < categories.size() - 1; i++) {
        categories[i] = categories[i + 1];
    }
    categories.pop_back();
<<<<<<< HEAD
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
=======
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
    return true;
}

    // Edit a category name
bool CategoryManager::renameCategory(const string& id, const string& newName, const int type){
    int index = findIndex(id, type);
    if (index == -1) return false;
<<<<<<< HEAD
<<<<<<< HEAD
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    list[index].name = newName;
=======
=======
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
    categories[index].name = newName;
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
    return true;
}

    // Nguoi dung nhap Nam hoac id (nay private ma nhi), nay co gi sua sau
bool CategoryManager::updateCategory(const string& id, const double amount, const int type){
    if (findIndex(id, type) == -1){
        return false;
    }
    int Index = findIndex(id, type);
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    list[Index].amount = amount;
    return true;

}

bool CategoryManager::getAllCategories(DynamicArray<Category>& categories_public, const int type, int& size) {
    size = 0;
<<<<<<< HEAD
<<<<<<< HEAD
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == type) {
            categories_public.push_back(list[i]);
=======
    for (int i = 0; i < categories.size(); i++) {
        if (categories[i].type == type) {
            categories_public.push_back(categories[i]);
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
=======
    for (int i = 0; i < categories.size(); i++) {
        if (categories[i].type == type) {
            categories_public.push_back(categories[i]);
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
            size++;
        }
    }
    return size > 0;
}