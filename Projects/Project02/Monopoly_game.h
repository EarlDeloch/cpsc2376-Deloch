#pragma once
#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Tile {
    string name;
    int price;
    int rent;
    string owner;

    Tile(string n, int p, int r) : name(n), price(p), rent(r), owner("") {}
};

struct Player {
    string name;
    int position;
    int balance;
    vector<int> ownedProperties;

    Player(string n, int b) : name(n), position(0), balance(b) {}
};

enum Status {
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

class MonopolyGame {
public:
    MonopolyGame();

    bool canBuyProperty() const;
    void buyProperty();
    void movePlayer(int roll);
    void nextPlayer();
    Status status() const;
    string currentPlayerName() const;
    void display() const;
    string getCurrentPropertyName() const;
    int getCurrentPropertyPrice() const;

private:
    vector<Player> players;
    vector<Tile> board;
    int currentPlayerIndex;
    Status gameStatus;
};

#endif
