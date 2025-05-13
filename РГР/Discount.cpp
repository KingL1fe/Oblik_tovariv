#define DISCOUNT_EXPORTS
#include "Discount.h"
Discount::Discount(int id, const string& name, double percentage)
    : id(id), name(name), percentage(percentage) {
}

int Discount::getId() const { return id; }
string Discount::getName() const { return name; }
double Discount::getPercentage() const { return percentage; }

void Discount::setName(const string& newName) { name = newName; }
void Discount::setPercentage(double newPercentage) { percentage = newPercentage; }
