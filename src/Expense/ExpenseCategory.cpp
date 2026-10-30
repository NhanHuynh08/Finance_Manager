#include "../../include/Expense/ExpenseCategory.h"  
#include <iostream>
using namespace std;

// Constructor

CategoryManager::CategoryManager(){

}

bool CategoryManager::isDuplicateID(string id) {
        for (int i = 0; i < categories.size(); i++) {
            if (categories[i].id == id)
                return true;
        }
        return false;
}

int CategoryManager::findCategoryByID(string id) {
        for (int i = 0; i < categories.size(); i++) {
            if (categories[i].id == id)
                return i;
        }
        return -1;
    }
    
    
bool CategoryManager::addCategory(string id, string name) {
        if (isDuplicateID(id)) {
            cout << "Category ID already exists!\n";
            return false;
        }

        if (id.empty() || name.empty()) {
            cout << "Invalid category information!\n";
            return false;
        }

        categories.push_back({id, name});

        cout << "Category added successfully!\n";
        return true;
    }

    // Edit category name
bool CategoryManager::editCategory(string id, string newName) {
        int index = findCategoryByID(id);

        if (index == -1 || newName.empty()) {
            cout << "Category not found or invalid name!\n";
            return false;
        }

        categories[index].name = newName;
        return true;
    }

    // Delete category
bool CategoryManager::deleteCategory(string id) {
        int index = findCategoryByID(id);

        if (index == -1) {
            cout << "Category not found!\n";
            return false;
        }

        categories.removeAt(index);
        return true;
    }

    // Display all categories
void CategoryManager::showCategories() {
        cout << "\n--- EXPENSE CATEGORIES ---\n";

        if (categories.empty()) {
            cout << "No categories available.\n";
            return;
        }

        for (int i = 0; i < categories.size(); i++) {
            cout << "[" << categories[i].id << "] "
                 << categories[i].name << "\n";
        }
    }

    // Get category name from ID
bool CategoryManager::getCategoryName(string id, string &name) {
        int index = findCategoryByID(id);

        if (index == -1)
            return false;

        name = categories[index].name;
        return true;
}