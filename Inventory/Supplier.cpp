#define SUPPLIER_EXPORTS
#include "Supplier.h"
#include"pch.h"
Supplier::Supplier(int id, const string& name, const string& contactInfo, const string& address)
    : id(id), name(name), contactInfo(contactInfo), address(address) {
}

int Supplier::getId() const { return id; }
string Supplier::getName() const { return name; }
string Supplier::getContactInfo() const { return contactInfo; }
string Supplier::getAddress() const { return address; }

void Supplier::setName(const string& newName) { name = newName; }
void Supplier::setContactInfo(const string& newContactInfo) { contactInfo = newContactInfo; }
void Supplier::setAddress(const string& newAddress) { address = newAddress; }
