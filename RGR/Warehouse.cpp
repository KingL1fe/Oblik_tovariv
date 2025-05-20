#include "Warehouse.h"

Warehouse::Warehouse() : id(0), location(""), capacity(0) {}
Warehouse::Warehouse(int id, const string& location, int capacity)
    : id(id), location(location), capacity(capacity) {
}

int Warehouse::getId() const { return id; }
string Warehouse::getLocation() const { return location; }
int Warehouse::getCapacity() const { return capacity; }

void Warehouse::setLocation(const string& location) { this->location = location; }
void Warehouse::setCapacity(int capacity) { this->capacity = capacity; }
