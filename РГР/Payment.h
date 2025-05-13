#pragma once
#include <string>

using namespace std;

class Payment {
private:
    int id;
    string method; // ���������: "������", "�����"
    double amount;
    string date;

public:
    Payment(int id, const string& method, double amount, const string& date);

    int getId() const;
    string getMethod() const;
    double getAmount() const;
    string getDate() const;

    void setMethod(const string& newMethod);
    void setAmount(double newAmount);
    void setDate(const string& newDate);
};
