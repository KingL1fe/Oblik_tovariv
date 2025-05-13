#pragma once
#include <vector>
#include <string>
#include "Product.h"

#ifdef INVENTORY_EXPORTS
#define INVENTORY_API __declspec(dllexport)
#else
#define INVENTORY_API __declspec(dllimport)
#endif

using namespace std;

class INVENTORY_API Inventory {
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
