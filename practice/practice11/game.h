#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game(const std::string& title, const std::string& id, int totalCopies);

    void displayInfo() const;
    void decreaseAvailable();
    void increaseAvailable();

    std::string getId() const;
    std::string getTitle() const;
    int getAvailableCopies() const;

private:
    std::string title;
    std::string id;
    int totalCopies;
    int availableCopies;
};

#endif
