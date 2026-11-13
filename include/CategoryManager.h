//Nguyen Ngoc Quynh Thi
#pragma once
#include <string>
#include "utils.h"
using namespace std;

class Category {
private:
    string id;
public:
    string name;
    double amount;
    int type;
    
    Category() : id(""), name(""), amount(0), type(0) {}

    // amount có giá trị mặc định = 0
    Category(const string& id, const string& name, int type, double amount = 0)
        : id(id), name(name), amount(amount), type(type) {}

    string getID() const { return id; }
};
class CategoryManager {
private:
    Category categories[1000]; // luu id
    int count; // dem data chua trong mang
    // Mang chua data
    int nextID;

    string generateID(int type); 
    //bool accessData();
public:
	CategoryManager();
    bool isDuplicateID(const string& name) const;

    void generate_ID(const string& name, Category &s);
    int findIndex(const string& name, int type) const;

    // Add a new category 
    bool addCategory(const string& name, const int type);
    
    // Delete a category
    bool deleteCategory(const string& id, const int type);
    // Edit a category name
    bool renameCategory(const string& id, const string& newName, const int type);

    // Update amount of money of a category
    bool updateCategory(const string& id, const double amount, const int type);
    // Query all categories of a specific type (expense or income) up to date (store results in variable categories)
    bool getAllCategories(DynamicArray<Category>& categories, const int type, int& size);
};


