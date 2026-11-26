//Nguyen Ngoc Quynh Thi
#pragma once
#include <string>
#include "utils.h"
#include <fstream>
#include "BinaryIO.h"
using namespace std;

class Category {
public:
    string id;
    string name;
    int type;
    double amount;
    
    Category() : id(""), name(""), type(0), amount(0) {}

    // amount có giá trị mặc định = 0
    Category(const string& id, const string& name, int type, double amount = 0)
        : id(id), name(name), type(type), amount(amount) {}
    void saveBinary(ofstream& Out) const; // because write work with const value
    bool loadBinary(ifstream& In); 
};

class CategoryManager {
private:  // Nay data nen private
    int nextID = 1;                         // bộ đếm để sinh ID

    string generateID(int type);
    DynamicArray<Category> INCcategories;
    DynamicArray<Category> EXPcategories;
    string filePath = "data/Category.bin"; 
    bool loadCategory();  // save INCcategories first
    bool saveCategory(); 
public:
    CategoryManager();

    ~CategoryManager(); 

    bool isDuplicateID(const string& id, int type);

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
    bool getAllCategories(DynamicArray<Category>& categories_public, const int type);
};
inline CategoryManager CM;