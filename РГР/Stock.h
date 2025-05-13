#pragma once
#include "Product.h"

using namespace std;

class Stock {
private:
    Product product;
    int availableQuantity;

public:
    Stock(const Product& product, int availableQuantity);

    Product getProduct() const;
    int getAvailableQuantity() const;

    void setAvailableQuantity(int newQuantity);
};
