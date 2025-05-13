#define PRODUCT_EXPORTS
#include "Product.h"
#include"pch.h"
Product::Product(int id, const string& name, int quantity, double price)
    : id(id), name(name), quantity(quantity), price(price) {
}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
int Product::getQuantity() const { return quantity; }
double Product::getPrice() const { return price; }

void Product::setName(const string& newName) { name = newName; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
void Product::setPrice(double newPrice) { price = newPrice; }
