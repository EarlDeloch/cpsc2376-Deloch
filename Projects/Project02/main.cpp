#include <iostream>
#include <string>
#include "monopoly_game.h"

using namespace std;

int main() {
    srand(time(nullptr)); // Seed random once
    MonopolyGame game;
    char input;
    int die1, die2, roll;

    while (game.status() == ONGOING) {
        game.display();

        cout << "\n" << game.currentPlayerName() << "'s turn!\n";
        cout << "Press 'r' to roll the dice.\n";
        cin >> input;

        if (input == 'r' || input == 'R') {
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;
            roll = die1 + die2;
            cout << game.currentPlayerName() << " rolled: " << die1 << " + " << die2 << " = " << roll << "\n";
            game.movePlayer(roll);
            game.nextPlayer();
        }
    }

    cout << "Game over!\n";
    return 0;
}
