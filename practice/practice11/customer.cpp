#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& customerID)
    : name(name), customerID(customerID) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getID() const {
    return customerID;
}
