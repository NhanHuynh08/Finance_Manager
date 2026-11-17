//Nguyen Ngoc Quynh Thi
#pragma once
#include <string>
#include "utils.h"
using namespace std;

class Category {
public:
    string name;
    double amount;
    int type;
    string id;
    
    Category() : id(""), name(""), amount(0), type(0) {}

    // amount có giá trị mặc định = 0
    Category(const string& id, const string& name, int type, double amount = 0)
        : id(id), name(name), amount(amount), type(type) {}

};
class CategoryManager {
private:
<<<<<<< HEAD
<<<<<<< HEAD
    DynamicArray<Category> INCcategories;
    DynamicArray<Category> EXPcategories;  // Nay data nen private
=======
    DynamicArray<Category> categories;  // mảng động, tự quản lý kích thước
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
=======
    DynamicArray<Category> categories;  // mảng động, tự quản lý kích thước
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
    int nextID;                         // bộ đếm để sinh ID

    string generateID(int type);
public:

	CategoryManager();
<<<<<<< HEAD
<<<<<<< HEAD
    bool isDuplicateID(const string& id, int type);
=======
    bool isDuplicateID(const string& id);
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121
=======
    bool isDuplicateID(const string& id);
>>>>>>> e6ba1aa84ac0df57511346e702dcbddf29388121

    void generate_ID(const string& name, Category &s);
    int findIndex(const string& id, int type);

    // Add a new category 
    bool addCategory(const string& id, const int type);
    
    // Delete a category
    bool deleteCategory(const string& id, const int type);
    // Edit a category name
    bool renameCategory(const string& id, const string& newName, const int type);

    // Update amount of money of a category
    bool updateCategory(const string& id, const double amount, const int type);
    // Query all categories of a specific type (expense or income) up to date (store results in variable categories)
    bool getAllCategories(DynamicArray<Category>& categories_public, const int type, int &size);
};


