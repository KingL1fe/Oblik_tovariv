#pragma once

#ifdef INVENTORY_EXPORTS
#define INVENTORY_API __declspec(dllexport)
#else
#define INVENTORY_API __declspec(dllimport)
#endif

#include <vector>
#include <string>
#include "Product.h"
#include "Category.h"
#include "Customer.h"
#include "Supplier.h"

using namespace std;

class INVENTORY_API Inventory {
private:
    vector<Product> products;
    vector<Category> categories;
    vector<Customer> customers;
    vector<Supplier> suppliers;

public:
    Inventory();

    void addProduct(const Product& product);
    bool removeProductById(int id);
    Product* findProductById(int id);
    vector<Product> getAllProducts() const;
    void clearInventory();

    void addCategory(const Category& category);
    bool removeCategoryById(int id);
    Category* findCategoryById(int id);
    vector<Category> getAllCategories() const;

    void addCustomer(const Customer& customer);
    bool removeCustomerById(int id);
    Customer* findCustomerById(int id);
    vector<Customer> getAllCustomers() const;

    void addSupplier(const Supplier& supplier);
    bool removeSupplierById(int id);
    Supplier* findSupplierById(int id);
    vector<Supplier> getAllSuppliers() const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};