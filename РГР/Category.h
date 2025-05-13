#pragma once

#ifdef CATEGORY_EXPORTS
#define CATEGORY_API __declspec(dllexport)
#else
#define CATEGORY_API __declspec(dllimport)
#endif

#include <string>

using namespace std;

class CATEGORY_API Category {
private:
    int id;
    string name;

public:
    Category(int id, const string& name);

    int getId() const;
    string getName() const;

    void setName(const string& newName);
};