#pragma once

#ifdef STOCK_EXPORTS
#define STOCK_API __declspec(dllexport)
#else
#define STOCK_API __declspec(dllimport)
#endif

#include "Product.h"

using namespace std;

class STOCK_API Stock {
private:
    Product* product;
    int availableQuantity;

public:
    Stock(Product* product, int availableQuantity);

    Product* getProduct() const;
    int getAvailableQuantity() const;

    void setAvailableQuantity(int newQuantity);
};
