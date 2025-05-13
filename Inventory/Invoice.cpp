#define INVOICE_EXPORTS
#include "Invoice.h"
Invoice::Invoice(int invoiceNumber, const Customer& customer, const Order& order, const string& dateIssued)
    : invoiceNumber(invoiceNumber), customer(customer), order(order), dateIssued(dateIssued) {
}

int Invoice::getInvoiceNumber() const { return invoiceNumber; }
Customer Invoice::getCustomer() const { return customer; }
Order Invoice::getOrder() const { return order; }
string Invoice::getDateIssued() const { return dateIssued; }

double Invoice::calculateTotal() const {
	return order.getTotalAmount();
