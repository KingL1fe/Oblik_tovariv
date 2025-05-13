#include "Stock.h"

Stock::Stock(const Product& product, int availableQuantity)
    : product(product), availableQuantity(availableQuantity) {
}

Product Stock::getProduct() const { return product; }
int Stock::getAvailableQuantity() const { return availableQuantity; }

void Stock::setAvailableQuantity(int newQuantity) { availableQuantity = newQuantity; }
