#define INVENTORY_EXPORTS
#include "Inventory.h"
#include <fstream>
#include <sstream>

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

void Inventory::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    // Збереження категорій
    file << "Categories:\n";
    for (const Category& category : categories) {
        file << category.getId() << ";" << category.getName() << "\n";
    }

    // Збереження продуктів
    file << "Products:\n";
    for (const Product& product : products) {
        file << product.getId() << ";" << product.getName() << ";"
            << product.getQuantity() << ";" << product.getPrice() << ";"
            << product.getCategoryId() << "\n";
    }

    file.close();
}

void Inventory::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    products.clear();
    categories.clear();
    string line;
    bool readingCategories = false;
    bool readingProducts = false;

    while (getline(file, line)) {
        if (line == "Categories:") {
            readingCategories = true;
            readingProducts = false;
            continue;
        }
        else if (line == "Products:") {
            readingCategories = false;
            readingProducts = true;
            continue;
        }

        if (readingCategories && !line.empty()) {
            stringstream ss(line);
            string idStr, name;
            getline(ss, idStr, ';');
            getline(ss, name);
            int id = stoi(idStr);
            categories.push_back(Category(id, name));
        }
        else if (readingProducts && !line.empty()) {
            stringstream ss(line);
            string idStr, name, quantityStr, priceStr, categoryIdStr;
            getline(ss, idStr, ';');
            getline(ss, name, ';');
            getline(ss, quantityStr, ';');
            getline(ss, priceStr, ';');
            getline(ss, categoryIdStr);
            int id = stoi(idStr);
            int quantity = stoi(quantityStr);
            double price = stod(priceStr);
            int categoryId = stoi(categoryIdStr);
            products.push_back(Product(id, name, quantity, price, categoryId));
        }
    }

    file.close();
}