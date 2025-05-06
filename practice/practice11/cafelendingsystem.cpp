#pragma once
#include "CafeLendingSystem.h"
#include <iostream>

// Add Game
void CafeLendingSystem::addGame(const Game& game) {
    games.push_back(game);
}

// Add Customer
void CafeLendingSystem::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

// Find game by ID
Game* CafeLendingSystem::findGameById(const std::string& gameID) {
    for (auto& game : games) {
        if (game.getId() == gameID) return &game;
    }
    return nullptr;
}

// Find customer by ID
Customer* CafeLendingSystem::findCustomerById(const std::string& customerID) {
    for (auto& customer : customers) {
        if (customer.getID() == customerID) return &customer;
    }
    return nullptr;
}

// Checkout
void CafeLendingSystem::checkOutGame(const std::string& gameID, const std::string& customerID, const std::string& dueDate) {
    Game* game = findGameById(gameID);
    if (!game || game->getAvailableCopies() == 0) {
        std::cout << "Game not available.\n";
        return;
    }

    if (!findCustomerById(customerID)) {
        std::cout << "Customer not found.\n";
        return;
    }

    game->decreaseAvailable();
    records.emplace_back(customerID, gameID, dueDate);
    std::cout << "Game checked out successfully.\n";
}

// Return Game
void CafeLendingSystem::returnGame(const std::string& gameID, const std::string& customerID) {
    Game* game = findGameById(gameID);
    if (game) game->increaseAvailable();

    std::cout << "Game returned.\n";
}

// Display Games
void CafeLendingSystem::showAvailableGames() const {
    for (const auto& game : games) {
        game.displayInfo();
    }
}

// Show Customer Records
void CafeLendingSystem::showCustomerRecords(const std::string& customerID) const {
    for (const auto& record : records) {
        if (record.getCustomerID() == customerID) {
            record.displayRecord();
        }
    }
}