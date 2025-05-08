#include "Inventory.h"

using namespace std;

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
