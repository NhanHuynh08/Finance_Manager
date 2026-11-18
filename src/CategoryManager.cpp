#include "include/CategoryManager.h"
#include "include/utils.h"
#include <iostream>

CategoryManager::CategoryManager() : nextID(1) {}

string CategoryManager::generateID(int type) {
    string prefix = (type == 0) ?  "EXP" : "INC" ;   // giả sử 0 = thu, 1 = chi
    string num = to_string(nextID++);              // lấy số hiện tại rồi tăng lên
    while (num.length() < 3) num = "0" + num;      // đệm số 0: 1 -> "001"
    return prefix + num;                           // vd: "EXP003"
}


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



bool CategoryManager::deleteCategory(const string& id, const int type) {
    int index = findIndex(id, type);
    if (index == -1) return false;

    auto& list = (type == 0) ? EXPcategories : INCcategories;
    list.removeAt(index);

    return true;
}

    // Edit a category name
bool CategoryManager::renameCategory(const string& id, const string& newName, const int type){
    int index = findIndex(id, type);
    if (index == -1) return false;
    auto& list = (type == 0) ? EXPcategories : INCcategories;
    list[index].name = newName;

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
    categories_public.empty();

    auto& list = (type == 0) ? EXPcategories : INCcategories;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].type == type) {
            categories_public.push_back(list[i]);
        }
    }
    return size > 0;
}