#pragma once
#include <string>

using namespace std;

class Discount {
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
