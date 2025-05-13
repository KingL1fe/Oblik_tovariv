#pragma once

#ifdef SUPPLIER_EXPORTS
#define SUPPLIER_API __declspec(dllexport)
#else
#define SUPPLIER_API __declspec(dllimport)
#endif

#include <string>

using namespace std;

class SUPPLIER_API Supplier {
private:
    int id;
    string name;
    string contactInfo;
    string address;

public:
    Supplier(int id, const string& name, const string& contactInfo, const string& address);

    int getId() const;
    string getName() const;
    string getContactInfo() const;
    string getAddress() const;

    void setName(const string& newName);
    void setContactInfo(const string& newContactInfo);
    void setAddress(const string& newAddress);
};
