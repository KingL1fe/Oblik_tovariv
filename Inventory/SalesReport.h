#pragma once
#include <string>

using namespace std;

#define SALESREPORT_EXPORTS
extern "C" {

    class SalesReport {
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
}
