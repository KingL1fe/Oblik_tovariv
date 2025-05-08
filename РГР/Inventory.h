#pragma once
#include <vector>
#include "Product.h"

using namespace std;

class Inventory {
private:
    vector<Product> products;

public:
    Inventory();

    void addProduct(const Product& product);
    bool removeProductById(int id);
    Product* findProductById(int id);
    vector<Product> getAllProducts() const;
    void clearInventory();
};
