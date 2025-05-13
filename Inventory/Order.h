#pragma once

#ifdef ORDER_EXPORTS
#define ORDER_API __declspec(dllexport)
#else
#define ORDER_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include <ctime>

using namespace std;

class ORDER_API Order {
private:
    int id;
    int customerId;
    string orderDate;
    string status;
    vector<pair<int, int>> productQuantities; // pair<productId, quantity>
    double totalAmount;

public:
    Order(int id, int customerId, const string& orderDate, const string& status, const vector<pair<int, int>>& productQuantities, double totalAmount);

    int getId() const;
    int getCustomerId() const;
    string getOrderDate() const;
    string getStatus() const;
    vector<pair<int, int>> getProductQuantities() const;
    double getTotalAmount() const;

    void setCustomerId(int newCustomerId);
    void setOrderDate(const string& newOrderDate);
    void setStatus(const string& newStatus);
    void setProductQuantities(const vector<pair<int, int>>& newProductQuantities);
    void setTotalAmount(double newTotalAmount);
};