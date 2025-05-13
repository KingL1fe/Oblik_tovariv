#define PAYMENT_EXPORTS
#include "Payment.h"

Payment::Payment(int id, const string& method, double amount, const string& date)
    : id(id), method(method), amount(amount), date(date) {
}

int Payment::getId() const { return id; }
string Payment::getMethod() const { return method; }
double Payment::getAmount() const { return amount; }
string Payment::getDate() const { return date; }

void Payment::setMethod(const string& newMethod) { method = newMethod; }
void Payment::setAmount(double newAmount) { amount = newAmount; }
void Payment::setDate(const string& newDate) { date = newDate; }
