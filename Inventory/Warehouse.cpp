#define WAREHOUSE_EXPORTS
#include "Warehouse.h"

Warehouse::Warehouse(int id, const string& name, const string& address)
    : id(id), name(name), address(address) {
}

int Warehouse::getId() const { return id; }
string Warehouse::getName() const { return name; }
string Warehouse::getAddress() const { return address; }

void Warehouse::setName(const string& newName) { name = newName; }
void Warehouse::setAddress(const string& newAddress) { address = newAddress; }
