#pragma once
#include <string>

using namespace std;

class SalesReport {
private:
    int id;
    string period; // ���������: "������ 2025"
    double totalSales;

public:
    SalesReport(int id, const string& period, double totalSales);

    int getId() const;
    string getPeriod() const;
    double getTotalSales() const;

    void setPeriod(const string& newPeriod);
    void setTotalSales(double newTotalSales);
};
