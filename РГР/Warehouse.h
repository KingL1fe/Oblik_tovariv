#pragma once
#include <string>

using namespace std;

class Warehouse {
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