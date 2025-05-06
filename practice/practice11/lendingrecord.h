#pragma once
#ifndef LENDINGRECORD_H
#define LENDINGRECORD_H

#include <string>

class LendingRecord {
public:
    LendingRecord(const std::string& customerID, const std::string& gameID, const std::string& dueDate);

    void displayRecord() const;

    std::string getCustomerID() const;
    std::string getGameID() const;

private:
    std::string customerID;
    std::string gameID;
    std::string dueDate;
};

#endif
