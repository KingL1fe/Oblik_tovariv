#pragma once

#ifdef PRODUCT_EXPORTS
#define PRODUCT_API __declspec(dllexport)
#else
#define PRODUCT_API __declspec(dllimport)
#endif

#include <string>

using namespace std;

class PRODUCT_API Product {
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