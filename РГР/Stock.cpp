#define STOCK_EXPORTS
#include "Stock.h"
Stock::Stock(Product* product, int availableQuantity)
    : product(product), availableQuantity(availableQuantity) {
}

Product* Stock::getProduct() const { return product; }
int Stock::getAvailableQuantity() const { return availableQuantity; }

void Stock::setAvailableQuantity(int newQuantity) { availableQuantity = newQuantity; }
