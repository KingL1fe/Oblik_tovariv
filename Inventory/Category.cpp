#include "Category.h"
#include"pch.h"
Category::Category(int id, const string& name, const string& description)
    : id(id), name(name), description(description) {
}

int Category::getId() const {
    return id;
}

string Category::getName() const {
    return name;
}

string Category::getDescription() const {
    return description;
}

void Category::setName(const string& newName) {
    name = newName;
}

void Category::setDescription(const string& newDescription) {
    description = newDescription;
}
