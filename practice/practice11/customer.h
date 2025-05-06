#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(const std::string& name, const std::string& customerID);

    std::string getName() const;
    std::string getID() const;

private:
    std::string name;
    std::string customerID;
};

#endif
