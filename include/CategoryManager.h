//Nguyen Ngoc Quynh Thi
#pragma once
#include <string>
#include "utils.h"
using namespace std;

struct Category {
    string id;
    string name;
}; 

class CategoryManager {
private:
    DynamicArray<Category> categoryData;
    // Check if a category ID already exists
    bool isDuplicateID(string& id);

    //bool accessData();
public:
	CategoryManager();

    // Add a new category
    bool addCategory(string& name, int type);
    // Delete a category
    bool deleteCategory(string& id, int type);
    // Edit a category name
    bool editCategory(string& id, string& newName, int type);

    // Query all categories of a specific type (expense or income) up to date
    bool getAllCategories(DynamicArray<Category>& categories, int type, int& size);
};
