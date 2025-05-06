#include "Game.h"
#include <iostream>

Game::Game(const std::string& title, const std::string& id, int totalCopies)
    : title(title), id(id), totalCopies(totalCopies), availableCopies(totalCopies) {}

void Game::displayInfo() const {
    std::cout << "Game: " << title
        << " | ID: " << id
        << " | Available: " << availableCopies
        << "/" << totalCopies << "\n";
}

void Game::decreaseAvailable() {
    if (availableCopies > 0) {
        availableCopies--;
    }
}

void Game::increaseAvailable() {
    if (availableCopies < totalCopies) {
        availableCopies++;
    }
}

std::string Game::getId() const {
    return id;
}

std::string Game::getTitle() const {
    return title;
}

int Game::getAvailableCopies() const {
    return availableCopies;
}
