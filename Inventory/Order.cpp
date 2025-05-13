#define ORDER_EXPORTS
#include "Order.h"

Order::Order(int id, const vector<Product>& products, const string& orderDate, const string& status)
    : id(id), productList(products), orderDate(orderDate), status(status) {
}

int Order::getId() const { return id; }

vector<Product> Order::getProductList() const { return productList; }

string Order::getOrderDate() const { return orderDate; }

string Order::getStatus() const { return status; }

void Order::setStatus(const string& newStatus) { status = newStatus; }

double Order::getTotalAmount() const {
    double total = 0.0;
    fo
