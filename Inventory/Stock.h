#pragma once
#include "Product.h"

using namespace std;

#define STOCK_EXPORTS
extern "C" {

    class Stock {
    private:
        Product* product;
        int availableQuantity;

    public:
        Stock(Product* product, int availableQuantity);

        Product* getProduct() const;
        int getAvailableQuantity() const;

        void setAvailableQuantity(int newQuantity);
    };
}
