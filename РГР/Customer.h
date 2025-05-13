#pragma once
#include <string>

#ifdef CUSTOMER_EXPORTS
#define CUSTOMER_API __declspec(dllexport)
#else
#define CUSTOMER_API __declspec(dllimport)
#endif

using namespace std;

class CUSTOMER_API Customer {
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
