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

void Inventory::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    // «береженн€ категор≥й
    file << "Categories:\n";
    for (const Category& category : categories) {
        file << category.getId() << ";" << category.getName() << "\n";
    }

    // «береженн€ продукт≥в
    file << "Products:\n";
    for (const Product& product : products) {
        file << product.getId() << ";" << product.getName() << ";"
            << product.getQuantity() << ";" << product.getPrice() << ";"
            << product.getCategoryId() << "\n";
    }

    // «береженн€ кл≥Їнт≥в
    file << "Customers:\n";
    for (const Customer& customer : customers) {
        file << customer.getId() << ";" << customer.getName() << ";"
            << customer.getContactInfo() << ";" << customer.getAddress() << "\n";
    }

    // «береженн€ постачальник≥в
    file << "Suppliers:\n";
    for (const Supplier& supplier : suppliers) {
        file << supplier.getId() << ";" << supplier.getName() << ";"
            << supplier.getContactInfo() << ";" << supplier.getAddress() << "\n";
    }

    // «береженн€ замовлень
    file << "Orders:\n";
    for (const Order& order : orders) {
        file << order.getId() << ";" << order.getCustomerId() << ";"
            << order.getOrderDate() << ";" << order.getStatus() << ";"
            << order.getTotalAmount() << ";";
        auto quantities = order.getProductQuantities();
        for (size_t i = 0; i < quantities.size(); ++i) {
            file << quantities[i].first << ":" << quantities[i].second;
            if (i < quantities.size() - 1) file << ",";
        }
        file << "\n";
    }

    file.close();
}

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
    string line;
    bool readingCategories = false;
    bool readingProducts = false;
    bool readingCustomers = false;
    bool readingSuppliers = false;
    bool readingOrders = false;

    while (getline(file, line)) {
        if (line == "Categories:") {
            readingCategories = true;
            readingProducts = false;
            readingCustomers = false;
            readingSuppliers = false;
            readingOrders = false;
            continue;
        }
        else if (line == "Products:") {
            readingCategories = false;
            readingProducts = true;
            readingCustomers = false;
            readingSuppliers = false;
            readingOrders = false;
            continue;
        }
        else if (line == "Customers:") {
            readingCategories = false;
            readingProducts = false;
            readingCustomers = true;
            readingSuppliers = false;
            readingOrders = false;
            continue;
        }
        else if (line == "Suppliers:") {
            readingCategories = false;
            readingProducts = false;
            readingCustomers = false;
            readingSuppliers = true;
            readingOrders = false;
            continue;
        }
        else if (line == "Orders:") {
            readingCategories = false;
            readingProducts = false;
            readingCustomers = false;
            readingSuppliers = false;
            readingOrders = true;
            continue;
        }

        if (readingCategories && !line.empty()) {
            stringstream ss(line);
            string idStr, name;
            getline(ss, idStr, ';');
            getline(ss, name);
            int id = stoi(idStr);
            categories.push_back(Category(id, name));
        }
        else if (readingProducts && !line.empty()) {
            stringstream ss(line);
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
        else if (readingCustomers && !line.empty()) {
            stringstream ss(line);
            string idStr, name, contactInfo, address;
            getline(ss, idStr, ';');
            getline(ss, name, ';');
            getline(ss, contactInfo, ';');
            getline(ss, address);
            int id = stoi(idStr);
            customers.push_back(Customer(id, name, contactInfo, address));
        }
        else if (readingSuppliers && !line.empty()) {
            stringstream ss(line);
            string idStr, name, contactInfo, address;
            getline(ss, idStr, ';');
            getline(ss, name, ';');
            getline(ss, contactInfo, ';');
            getline(ss, address);
            int id = stoi(idStr);
            suppliers.push_back(Supplier(id, name, contactInfo, address));
        }
        else if (readingOrders && !line.empty()) {
            stringstream ss(line);
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
    }

    file.close();
}