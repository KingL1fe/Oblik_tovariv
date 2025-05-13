#pragma once

#ifdef WAREHOUSE_EXPORTS
#define WAREHOUSE_API __declspec(dllexport)
#else
#define WAREHOUSE_API __declspec(dllimport)
#endif

#include <string>

using namespace std;

class WAREHOUSE_API Warehouse {
private:
    int id;
    string name;
    string address;

public:
    Warehouse(int id, const string& name, const string& address);

    int getId() const;
    string getName() const;
    string getAddress() const;

    void setName(const string& newName);
    void setAddress(const string& newAddress);
};