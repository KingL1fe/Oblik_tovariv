#pragma once
#include <string>

// Для експорту класу та функцій
#ifdef CATEGORY_EXPORTS
#define CATEGORY_API __declspec(dllexport)
#else
#define CATEGORY_API __declspec(dllimport)
#endif

using namespace std;

class CATEGORY_API Category {
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
