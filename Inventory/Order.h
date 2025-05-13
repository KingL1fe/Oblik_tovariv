#pragma once
#include <vector>
#include <string>
#include "Product.h"

#ifdef ORDER_EXPORTS
#define ORDER_API __declspec(dllexport)
#else
#define ORDER_API __declspec(dllimport)
#endif

using namespace std;

class ORDER_API Order {
private:
    int id;
    vector<Product> productList;
    string orderDate;
    string status;

public:
    Order(int id, const vector<Product>& products, const string& orderDate, const string& status);

    int getId() const;
    vector<Product> getProductList() const;
    string getOrderDate() const;
    string getStatus() const;

    void setStatus(const string& newStatus);
    double getTotalAmount() const;
};
