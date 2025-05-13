#include "SalesReport.h"

SalesReport::SalesReport(int id, const string& period, double totalSales)
    : id(id), period(period), totalSales(totalSales) {
}

int SalesReport::getId() const { return id; }
string SalesReport::getPeriod() const { return period; }
double SalesReport::getTotalSales() const { return totalSales; }
void SalesReport::setPeriod(const string& newPeriod) { period = newPeriod; }
void SalesReport::setTotalSales(double newTotalSales) { totalSales = newTotalSales; }