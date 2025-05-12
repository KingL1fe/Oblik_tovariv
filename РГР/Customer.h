#pragma once
#include <string>

using namespace std;

class Customer {
private:
    int id;
    string name;
    string contactInfo;
    string address;

public:
    Customer(int id, const string& name, const string& contactInfo, const string& address);

    int getId() const;
    string getName() const;
    string getContactInfo() const;
    string getAddress() const;

    void setName(const string& newName);
    void setContactInfo(const string& newContactInfo);
    void setAddress(const string& newAddress);
};