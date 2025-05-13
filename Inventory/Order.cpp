#define ORDER_EXPORTS
#include "Order.h"

Order::Order(int id, int customerId, const string& orderDate, const string& status, const vector<pair<int, int>>& productQuantities, double totalAmount)
    : id(id), customerId(customerId), orderDate(orderDate), status(status), productQuantities(productQuantities), totalAmount(totalAmount) {
}

int Order::getId() const { return id; }
int Order::getCustomerId() const { return customerId; }
string Order::getOrderDate() const { return orderDate; }
string Order::getStatus() const { return status; }
vector<pair<int, int>> Order::getProductQuantities() const { return productQuantities; }
double Order::getTotalAmount() const { return totalAmount; }

void Order::setCustomerId(int newCustomerId) { customerId = newCustomerId; }
void Order::setOrderDate(const string& newOrderDate) { orderDate = newOrderDate; }
void Order::setStatus(const string& newStatus) { status = newStatus; }
void Order::setProductQuantities(const vector<pair<int, int>>& newProductQuantities) { productQuantities = newProductQuantities; }
void Order::setTotalAmount(double newTotalAmount) { totalAmount = newTotalAmount; }