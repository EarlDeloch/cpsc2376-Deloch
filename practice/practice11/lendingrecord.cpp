#include "LendingRecord.h"
#include <iostream>

LendingRecord::LendingRecord(const std::string& customerID, const std::string& gameID, const std::string& dueDate)
    : customerID(customerID), gameID(gameID), dueDate(dueDate) {}

void LendingRecord::displayRecord() const {
    std::cout << "Customer ID: " << customerID
        << " | Game ID: " << gameID
        << " | Due: " << dueDate << "\n";
}

std::string LendingRecord::getCustomerID() const {
    return customerID;
}

std::string LendingRecord::getGameID() const {
    return gameID;
}
