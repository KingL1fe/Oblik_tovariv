#pragma once
#include <string>  

#ifdef WAREHOUSE_EXPORTS
#define WAREHOUSE_API __declspec(dllexport)
#else
#define WAREHOUSE_API __declspec(dllimport)
#endif


class Warehouse {
private:
    int id;
    std::string location;

public:
    Warehouse(int id, const std::string& location) : id(id), location(location) {}

    int getId() const {
        return id;
    }

    std::string getLocation() const {
        return location;
    }
};