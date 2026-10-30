#ifndef CATEGORY_H  // Header guard: tránh việc file bị include lặp lại nhiều lần
#define CATEGORY_H
#include <iostream>
#include <string> // Thêm thư viện này
#include "../../include/DynamicArray.h"  
using namespace std;

class CategoryManager {
private:
    struct Category {
        string id;
        string name;
    };

    DynamicArray<Category> categories;

public:
	CategoryManager();
    bool isDuplicateID(string id);

    // Find category by ID
    int findCategoryByID(string id);

    // Add a new category
    bool addCategory(string id, string name);

    // Edit category name
    bool editCategory(string id, string newName);
    
    // Delete category
    bool deleteCategory(string id);

    // Display all categories
    
    void showCategories();
    // Get category name from ID
    bool getCategoryName(string id, string &name);
};

#endif