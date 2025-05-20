#define INVENTORY_EXPORTS
#include "Inventory.h"
#include <fstream>
#include <sstream>

// ... інші методи без змін ...

// ✅ WAREHOUSE methods
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
    if (!file.is_open()) return;

    clearInventory();
    string line;
    enum Section { NONE, CATEGORIES, PRODUCTS, CUSTOMERS, SUPPLIERS, ORDERS, WAREHOUSES } section = NONE;

    while (getline(file, line)) {
        if (line == "Categories:") { section = CATEGORIES; continue; }
        else if (line == "Products:") { section = PRODUCTS; continue; }
        else if (line == "Customers:") { section = CUSTOMERS; continue; }
        else if (line == "Suppliers:") { section = SUPPLIERS; continue; }
        else if (line == "Orders:") { section = ORDERS; continue; }
        else if (line == "Warehouses:") { section = WAREHOUSES; continue; }
        if (line.empty()) continue;

        stringstream ss(line);

        if (section == CATEGORIES) {
            string idStr, name;
            getline(ss, idStr, ';'); getline(ss, name);
            categories.push_back(Category(stoi(idStr), name));
        }
        else if (section == PRODUCTS) {
            string idStr, name, qtyStr, priceStr, catIdStr;
            getline(ss, idStr, ';'); getline(ss, name, ';'); getline(ss, qtyStr, ';');
            getline(ss, priceStr, ';'); getline(ss, catIdStr);
            products.push_back(Product(stoi(idStr), name, stoi(qtyStr), stod(priceStr), stoi(catIdStr)));
        }
        else if (section == CUSTOMERS) {
            string idStr, name, contact, address;
            getline(ss, idStr, ';'); getline(ss, name, ';'); getline(ss, contact, ';'); getline(ss, address);
            customers.push_back(Customer(stoi(idStr), name, contact, address));
        }
        else if (section == SUPPLIERS) {
            string idStr, name, contact, address;
            getline(ss, idStr, ';'); getline(ss, name, ';'); getline(ss, contact, ';'); getline(ss, address);
            suppliers.push_back(Supplier(stoi(idStr), name, contact, address));
        }
        else if (section == ORDERS) {
            string idStr, custIdStr, date, status, totalStr, prodStr;
            getline(ss, idStr, ';'); getline(ss, custIdStr, ';'); getline(ss, date, ';');
            getline(ss, status, ';'); getline(ss, totalStr, ';'); getline(ss, prodStr);

            vector<pair<int, int>> pq;
            stringstream prodSS(prodStr);
            string pairStr;
            while (getline(prodSS, pairStr, ',')) {
                size_t pos = pairStr.find(':');
                if (pos != string::npos) {
                    int pid = stoi(pairStr.substr(0, pos));
                    int qty = stoi(pairStr.substr(pos + 1));
                    pq.emplace_back(pid, qty);
                }
            }

            orders.push_back(Order(stoi(idStr), stoi(custIdStr), date, status, pq, stod(totalStr)));
        }
        else if (section == WAREHOUSES) {
            string idStr, location, capStr;
            getline(ss, idStr, ';'); getline(ss, location, ';'); getline(ss, capStr);
            warehouses.push_back(Warehouse(stoi(idStr), location, stoi(capStr)));
        }
    }

    file.close();
}

