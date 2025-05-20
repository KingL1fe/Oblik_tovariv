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
#include "Order.h"
#include "Warehouse.h"  // ✅ Додано

using namespace std;

class INVENTORY_API Inventory {
private:
    vector<Product> products;
    vector<Category> categories;
    vector<Customer> customers;
    vector<Supplier> suppliers;
    vector<Order> orders;
    vector<Warehouse> warehouses;  // ✅ Додано

public:
    Inventory();

    // Products
    void addProduct(const Product& product);
    bool removeProductById(int id);
    Product* findProductById(int id);
    vector<Product> getAllProducts() const;

    // Categories
    void addCategory(const Category& category);
    bool removeCategoryById(int id);
    Category* findCategoryById(int id);
    vector<Category> getAllCategories() const;

    // Customers
    void addCustomer(const Customer& customer);
    bool removeCustomerById(int id);
    Customer* findCustomerById(int id);
    vector<Customer> getAllCustomers() const;

    // Suppliers
    void addSupplier(const Supplier& supplier);
    bool removeSupplierById(int id);
    Supplier* findSupplierById(int id);
    vector<Supplier> getAllSuppliers() const;

    // Orders
    void addOrder(const Order& order);
    bool removeOrderById(int id);
    Order* findOrderById(int id);
    vector<Order> getAllOrders() const;

    // Warehouses ✅
    void addWarehouse(const Warehouse& warehouse);
    bool removeWarehouseById(int id);
    Warehouse* findWarehouseById(int id);
    vector<Warehouse> getAllWarehouses() const;

    // Persistence
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    // Clear All
    void clearInventory();
};
