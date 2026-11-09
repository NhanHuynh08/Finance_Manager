//Nguyen Ngoc Quynh Thi
#pragma once
#include <string>
#include "utils.h"
using namespace std;

class Category {
public:
    string id;
    string name;
    double amount;
    int type;
};
class CategoryManager {
private:
    //bool accessData();
public:
	CategoryManager();

    // Add a new category 
    bool addCategory(const string& name, int type);
    // Delete a category
    bool deleteCategory(const string& id, int type);
    // Edit a category name
    bool renameCategory(const string& id, const string& newName, int type);

    // Update amount of money of a category
    bool updateCategory(const string& id, const double amount, int type);
    // Query all categories of a specific type (expense or income) up to date (store results in variable categories)
    bool getAllCategories(DynamicArray<Category>& categories, int type, int& size);
};
