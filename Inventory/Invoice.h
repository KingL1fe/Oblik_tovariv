#pragma once
#include <string>
#include "Customer.h"
#include "Order.h"

#ifdef INVOICE_EXPORTS
#define INVOICE_API __declspec(dllexport)
#else
#define INVOICE_API __declspec(dllimport)
#endif

using namespace std;

class INVOICE_API Invoice {
private:
    int invoiceNumber;
    Customer customer;
    Order order;
    string dateIssued;

public:
    Invoice(int invoiceNumber, const Customer& customer, const Order& order, const string& dateIssued);

    int getInvoiceNumber() const;
    Customer getCustomer() const;
    Order getOrder() const;
    string getDateIssued() const;

    double calculateTotal() const;
};
