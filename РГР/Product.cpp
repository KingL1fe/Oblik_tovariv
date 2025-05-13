#define PRODUCT_EXPORTS
#include "Product.h"

Product::Product(int id, const string& name, int quantity, double price, int categoryId)
    : id(id), name(name), quantity(quantity), price(price), categoryId(categoryId) {
}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
int Product::getQuantity() const { return quantity; }
double Product::getPrice() const { return price; }
int Product::getCategoryId() const { return categoryId; }

void Product::setName(const string& newName) { name = newName; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setCategoryId(int newCategoryId) { categoryId = newCategoryId; }