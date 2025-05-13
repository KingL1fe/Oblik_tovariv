#pragma once

#ifdef SALESREPORT_EXPORTS
#define SALESREPORT_API __declspec(dllexport)
#else
#define SALESREPORT_API __declspec(dllimport)
#endif

#include <string>

using namespace std;

class SALESREPORT_API SalesReport {
private:
    int id;
    string period;
    double totalSales;

public:
    SalesReport(int id, const string& period, double totalSales);

    int getId() const;
    string getPeriod() const;
    double getTotalSales() const;

    void setPeriod(const string& newPeriod);
    void setTotalSales(double newTotalSales);
};