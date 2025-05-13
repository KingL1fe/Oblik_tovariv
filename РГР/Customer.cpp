#define CUSTOMER_EXPORTS
#include "Customer.h"
Customer::Customer(int id, const string& name, const string& contactInfo, const string& address)
    : id(id), name(name), contactInfo(contactInfo), address(address) {
}

int Customer::getId() const { return id; }
string Customer::getName() const { return name; }
string Customer::getContactInfo() const { return contactInfo; }
string Customer::getAddress() const { return address; }

void Customer::setName(const string& newName) { name = newName; }
void Customer::setContactInfo(const string& newContactInfo) { contactInfo = newContactInfo; }
void Customer::setAddress(const string& newAddress) { address = newAddress; }
