#pragma once
#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product(int id, const string& name, int quantity, double price);

    int getId() const;
    string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setName(const string& newName);
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);
};
