#define INVENTORY_EXPORTS
#include "Inventory.h"
#include <fstream>
#include <sstream>

Inventory::Inventory() {}

void Inventory::addProduct(const Product& product) {
    products.push_back(product);
}

bool Inventory::removeProductById(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;
}

Product* Inventory::findProductById(int id) {
    for (auto& product : products) {
        if (product.getId() == id) {
            return &product;
        }
    }
    return nullptr;
}

vector<Product> Inventory::getAllProducts() const {
    return products;
}

void Inventory::clearInventory() {
    products.clear();
}

void Inventory::addCategory(const Category& category) {
    categories.push_back(category);
}

bool Inventory::removeCategoryById(int id) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if (it->getId() == id) {
            categories.erase(it);
            return true;
        }
    }
    return false;
}

Category* Inventory::findCategoryById(int id) {
    for (auto& category : categories) {
        if (category.getId() == id) {
            return &category;
        }
    }
    return nullptr;
}

vector<Category> Inventory::getAllCategories() const {
    return categories;
}

void Inventory::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

bool Inventory::removeCustomerById(int id) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->getId() == id) {
            customers.erase(it);
            return true;
        }
    }
    return false;
}

Customer* Inventory::findCustomerById(int id) {
    for (auto& customer : customers) {
        if (customer.getId() == id) {
            return &customer;
        }
    }
    return nullptr;
}

vector<Customer> Inventory::getAllCustomers() const {
    return customers;
}

void Inventory::addSupplier(const Supplier& supplier) {
    suppliers.push_back(supplier);
}

bool Inventory::removeSupplierById(int id) {
    for (auto it = suppliers.begin(); it != suppliers.end(); ++it) {
        if (it->getId() == id) {
            suppliers.erase(it);
            return true;
        }
    }
    return false;
}

Supplier* Inventory::findSupplierById(int id) {
    for (auto& supplier : suppliers) {
        if (supplier.getId() == id) {
            return &supplier;
        }
    }
    return nullptr;
}

vector<Supplier> Inventory::getAllSuppliers() const {
    return suppliers;
}

void Inventory::addOrder(const Order& order) {
    orders.push_back(order);
}

bool Inventory::removeOrderById(int id) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getId() == id) {
            orders.erase(it);
            return true;
        }
    }
    return false;
}

Order* Inventory::findOrderById(int id) {
    for (auto& order : orders) {
        if (order.getId() == id) {
            return &order;
        }
    }
    return nullptr;
}

vector<Order> Inventory::getAllOrders() const {
    return orders;
}

void Inventory::addWarehouse(const Warehouse& warehouse) {
    warehouses.push_back(warehouse);
}

bool Inventory::removeWarehouseById(int id) {
    for (auto it = warehouses.begin(); it != warehouses.end(); ++it) {
        if (it->getId() == id) {
            warehouses.erase(it);
            return true;
        }
    }
    return false;
}

Warehouse* Inventory::findWarehouseById(int id) {
    for (auto& warehouse : warehouses) {
        if (warehouse.getId() == id) {
            return &warehouse;
        }
    }
    return nullptr;
}

vector<Warehouse> Inventory::getAllWarehouses() const {
    return warehouses;
}

// ✅ SAVE
void Inventory::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) return;

    file << "Categories:\n";
    for (const auto& c : categories)
        file << c.getId() << ";" << c.getName() << "\n";

    file << "Products:\n";
    for (const auto& p : products)
        file << p.getId() << ";" << p.getName() << ";" << p.getQuantity() << ";" << p.getPrice() << ";" << p.getCategoryId() << "\n";

    file << "Customers:\n";
    for (const auto& c : customers)
        file << c.getId() << ";" << c.getName() << ";" << c.getContactInfo() << ";" << c.getAddress() << "\n";

    file << "Suppliers:\n";
    for (const auto& s : suppliers)
        file << s.getId() << ";" << s.getName() << ";" << s.getContactInfo() << ";" << s.getAddress() << "\n";

    file << "Orders:\n";
    for (const auto& o : orders) {
        file << o.getId() << ";" << o.getCustomerId() << ";" << o.getOrderDate() << ";" << o.getStatus() << ";" << o.getTotalAmount() << ";";
        auto q = o.getProductQuantities();
        for (size_t i = 0; i < q.size(); ++i) {
            file << q[i].first << ":" << q[i].second;
            if (i < q.size() - 1) file << ",";
        }
        file << "\n";
    }

    file << "Warehouses:\n";
    for (const auto& w : warehouses) {
        file << w.getId() << ";" << w.getLocation() << ";" << w.getCapacity() << "\n";
    }

    file.close();
}

// ✅ LOAD
void Inventory::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return;
    }

    products.clear();
    categories.clear();
    customers.clear();
    suppliers.clear();
    orders.clear();
    warehouses.clear();

    string line;
    bool readingCategories = false;
    bool readingProducts = false;
    bool readingCustomers = false;
    bool readingSuppliers = false;
    bool readingOrders = false;
    bool readingWarehouses = false;

    while (getline(file, line)) {
        if (line == "Categories:") {
            readingCategories = true;
            readingProducts = readingCustomers = readingSuppliers = readingOrders = readingWarehouses = false;
            continue;
        }
        else if (line == "Products:") {
            readingProducts = true;
            readingCategories = readingCustomers = readingSuppliers = readingOrders = readingWarehouses = false;
            continue;
        }
        else if (line == "Customers:") {
            readingCustomers = true;
            readingCategories = readingProducts = readingSuppliers = readingOrders = readingWarehouses = false;
            continue;
        }
        else if (line == "Suppliers:") {
            readingSuppliers = true;
            readingCategories = readingProducts = readingCustomers = readingOrders = readingWarehouses = false;
            continue;
        }
        else if (line == "Orders:") {
            readingOrders = true;
            readingCategories = readingProducts = readingCustomers = readingSuppliers = readingWarehouses = false;
            continue;
        }
        else if (line == "Warehouses:") {
            readingWarehouses = true;
            readingCategories = readingProducts = readingCustomers = readingSuppliers = readingOrders = false;
            continue;
        }

        if (line.empty()) continue;

        stringstream ss(line);

        if (readingCategories) {
            string idStr, name;
            getline(ss, idStr, ';');
            getline(ss, name);
            int id = stoi(idStr);
            categories.push_back(Category(id, name));
        }
        else if (readingProducts) {
            string idStr, name, quantityStr, priceStr, categoryIdStr;
            getline(ss, idStr, ';');
            getline(ss, name, ';');
            getline(ss, quantityStr, ';');
            getline(ss, priceStr, ';');
            getline(ss, categoryIdStr);
            int id = stoi(idStr);
            int quantity = stoi(quantityStr);
            double price = stod(priceStr);
            int categoryId = stoi(categoryIdStr);
            products.push_back(Product(id, name, quantity, price, categoryId));
        }
        else if (readingCustomers) {
            string idStr, name, contactInfo, address;
            getline(ss, idStr, ';');
            getline(ss, name, ';');
            getline(ss, contactInfo, ';');
            getline(ss, address);
            int id = stoi(idStr);
            customers.push_back(Customer(id, name, contactInfo, address));
        }
        else if (readingSuppliers) {
            string idStr, name, contactInfo, address;
            getline(ss, idStr, ';');
            getline(ss, name, ';');
            getline(ss, contactInfo, ';');
            getline(ss, address);
            int id = stoi(idStr);
            suppliers.push_back(Supplier(id, name, contactInfo, address));
        }
        else if (readingOrders) {
            string idStr, customerIdStr, orderDate, status, totalAmountStr, quantitiesStr;
            getline(ss, idStr, ';');
            getline(ss, customerIdStr, ';');
            getline(ss, orderDate, ';');
            getline(ss, status, ';');
            getline(ss, totalAmountStr, ';');
            getline(ss, quantitiesStr);

            int id = stoi(idStr);
            int customerId = stoi(customerIdStr);
            double totalAmount = stod(totalAmountStr);

            vector<pair<int, int>> productQuantities;
            stringstream quantitiesSS(quantitiesStr);
            string quantityPair;
            while (getline(quantitiesSS, quantityPair, ',')) {
                stringstream pairSS(quantityPair);
                string productIdStr, quantityStr;
                getline(pairSS, productIdStr, ':');
                getline(pairSS, quantityStr);
                int productId = stoi(productIdStr);
                int quantity = stoi(quantityStr);
                productQuantities.push_back({ productId, quantity });
            }

            orders.push_back(Order(id, customerId, orderDate, status, productQuantities, totalAmount));
        }
        else if (readingWarehouses) {
            string idStr, location, capacityStr;
            getline(ss, idStr, ';');
            getline(ss, location, ';');
            getline(ss, capacityStr);
            int id = stoi(idStr);
            int capacity = stoi(capacityStr);
            warehouses.push_back(Warehouse(id, location, capacity));
        }
    }

    file.close();
}


