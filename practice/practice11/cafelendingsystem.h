#pragma once
#ifndef CAFELENDINGSYSTEM_H
#define CAFELENDINGSYSTEM_H

#include <vector>
#include <string>
#include "Game.h"
#include "Customer.h"
#include "LendingRecord.h"

class CafeLendingSystem {
public:
    void addGame(const Game& game);
    void addCustomer(const Customer& customer);
    void checkOutGame(const std::string& gameID, const std::string& customerID, const std::string& dueDate);
    void returnGame(const std::string& gameID, const std::string& customerID);
    void showAvailableGames() const;
    void showCustomerRecords(const std::string& customerID) const;

private:
    std::vector<Game> games;
    std::vector<Customer> customers;
    std::vector<LendingRecord> records;

    Game* findGameById(const std::string& gameID);
    Customer* findCustomerById(const std::string& customerID);
};

#endif
