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
    string location;
    int capacity;

public:

    Warehouse(int id, const std::string& location) : id(id), location(location) {}
    Warehouse();
    Warehouse(int id, const string& location, int capacity);

    int getId() const;
    string getLocation() const;
    int getCapacity() const;

    void setLocation(const string& location);
    void setCapacity(int capacity);
};
