#define INVENTORY_EXPORTS
#include "Inventory.h"

Inventory::Inventory() {}

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
}

bool Inventory::removeProductById(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;
}

Product* Inventory::findProductById(int id) {
    for (auto& product : products) {
        if (product.getId() == id) {
            return &product;
        }
    }
    return nullptr;
}

vector<Product> Inventory::getAllProducts() const {
    return products;
}

void Inventory::clearInventory() {
    products.clear();
}

void Inventory::addCategory(const Category& category) {
    categories.push_back(category);
}

bool Inventory::removeCategoryById(int id) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if (it->getId() == id) {
            categories.erase(it);
            return true;
        }
    }
    return false;
}

Category* Inventory::findCategoryById(int id) {
    for (auto& category : categories) {
        if (category.getId() == id) {
            return &category;
        }
    }
    return nullptr;
}

vector<Category> Inventory::getAllCategories() const {
    return categories;
}