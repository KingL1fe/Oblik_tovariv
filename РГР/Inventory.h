#pragma once

#ifdef INVENTORY_EXPORTS
#define INVENTORY_API __declspec(dllexport)
#else
#define INVENTORY_API __declspec(dllimport)
#endif

#include <vector>
#include <string>
#include "Product.h"
#include "Category.h"

using namespace std;

class INVENTORY_API Inventory {
private:
    vector<Product> products;
    vector<Category> categories;

public:
    Inventory();

    void addProduct(const Product& product);
    bool removeProductById(int id);
    Product* findProductById(int id);
    vector<Product> getAllProducts() const;
    void clearInventory();

    void addCategory(const Category& category);
    bool removeCategoryById(int id);
    Category* findCategoryById(int id);
    vector<Category> getAllCategories() const;
};