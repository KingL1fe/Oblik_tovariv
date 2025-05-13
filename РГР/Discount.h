#pragma once
#include <string>

#ifdef DISCOUNT_EXPORTS
#define DISCOUNT_API __declspec(dllexport)
#else
#define DISCOUNT_API __declspec(dllimport)
#endif

using namespace std;

class DISCOUNT_API Discount {
private:
    int id;
    string name;
    double percentage;

public:
    Discount(int id, const string& name, double percentage);

    int getId() const;
    string getName() const;
    double getPercentage() const;

    void setName(const string& newName);
    void setPercentage(double newPercentage);
};
