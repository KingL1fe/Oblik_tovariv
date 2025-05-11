#pragma once
#include <string>

using namespace std;

class Category {
private:
    int id;
    string name;
    string description;

public:
    Category(int id, const string& name, const string& description);

    int getId() const;
    string getName() const;
    string getDescription() const;

    void setName(const string& newName);
    void setDescription(const string& newDescription);
};
