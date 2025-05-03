#include "monopoly_game.h"

MonopolyGame::MonopolyGame() : currentPlayerIndex(0), gameStatus(ONGOING) {
    players.push_back(Player("PLYR1", 1500));
    players.push_back(Player("PLYR2", 1500));

    board = {
        {"GO", 0, 0},
        {"Mediterranean Ave", 60, 2},
        {"Community Chest", 0, 0},
        {"Baltic Ave", 60, 4},
        {"Income Tax", 0, 0},
        {"Reading Railroad", 200, 25},
        {"Oriental Ave", 100, 6},
        {"Chance", 0, 0},
        {"Vermont Ave", 100, 6},
        {"Connecticut Ave", 120, 8},
        {"Jail", 0, 0},
        {"St. Charles Place", 140, 10},
        {"Electric Company", 150, 10},
        {"States Ave", 140, 10},
        {"Virginia Ave", 160, 12},
        {"Pennsylvania Railroad", 200, 25},
        {"St. James Place", 180, 14},
        {"Community Chest", 0, 0},
        {"Tennessee Ave", 180, 14},
        {"New York Ave", 200, 16},
        {"Free Parking", 0, 0},
        {"Kentucky Ave", 220, 18},
        {"Chance", 0, 0},
        {"Indiana Ave", 220, 18},
        {"Illinois Ave", 240, 20},
        {"B&O Railroad", 200, 25},
        {"Atlantic Ave", 260, 22},
        {"Ventnor Ave", 260, 22},
        {"Water Works", 150, 10},
        {"Marvin Gardens", 280, 24},
        {"Go To Jail", 0, 0},
        {"Pacific Ave", 300, 26},
        {"North Carolina Ave", 300, 26},
        {"Community Chest", 0, 0},
        {"Pennsylvania Ave", 320, 28},
        {"Short Line", 200, 25},
        {"Chance", 0, 0},
        {"Park Place", 350, 35},
        {"Luxury Tax", 0, 0},
        {"Boardwalk", 400, 50}
    };
}

bool MonopolyGame::canBuyProperty() const {
    const Tile& tile = board[players[currentPlayerIndex].position];
    return tile.price > 0 && tile.owner.empty();
}

void MonopolyGame::buyProperty() {
    Player& player = players[currentPlayerIndex];
    Tile& tile = board[player.position];

    if (tile.price > 0 && tile.owner.empty()) {
        if (player.balance >= tile.price) {
            player.balance -= tile.price;
            tile.owner = player.name;
            player.ownedProperties.push_back(player.position);
            cout << " You have purchased " << tile.name << " for $" << tile.price
                << ". New balance: $" << player.balance << "\n";
        }
        else {
            cout << " You don't have enough money to purchase this property!\n";
        }
    }
    else {
        cout << " This property has already been bought.\n";
    }
}

void MonopolyGame::movePlayer(int roll) {
    Player& player = players[currentPlayerIndex];
    int oldPos = player.position;
    player.position = (player.position + roll) % board.size();

    // Passed GO
    if (player.position < oldPos) {
        player.balance += 200;
        cout << player.name << " passed GO! Collected $200.\n";
    }

    Tile& tile = board[player.position];
    cout << player.name << " moved to " << tile.name << "\n";

    if (tile.price > 0 && tile.owner.empty()) {
        // Unowned property — offer to buy
        string buyInput;
        cout << " " << tile.name << " is available for $" << tile.price << ".\n";
        cout << "Would you like to buy it? (y/n): ";
        cin >> buyInput;

        if (buyInput == "y" || buyInput == "Y") {
            buyProperty();
        }
        else {
            cout << " You chose not to buy the property.\n";
        }
    }
    else if (!tile.owner.empty() && tile.owner != player.name) {
        // Owned by opponent — pay rent
        int rent = tile.rent;
        cout << " " << tile.name << " is owned by " << tile.owner
            << ". You must pay $" << rent << " in rent.\n";

        player.balance -= rent;

        for (auto& p : players) {
            if (p.name == tile.owner) {
                p.balance += rent;
                break;
            }
        }

        cout << player.name << "'s new balance: $" << player.balance << "\n";
    }
    else {
        cout << "This space is not for sale or already owned by you.\n";
    }
}

void MonopolyGame::nextPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

Status MonopolyGame::status() const {
    for (const auto& p : players) {
        if (p.balance < 0) {
            return (p.name == "PLYR1") ? PLAYER_2_WINS : PLAYER_1_WINS;
        }
    }
    return ONGOING;
}

string MonopolyGame::currentPlayerName() const {
    return players[currentPlayerIndex].name;
}

void MonopolyGame::display() const {
    cout << "\n Board Overview:\n";
    for (int i = 0; i < board.size(); ++i) {
        cout << setw(2) << i << ": " << setw(20) << board[i].name;

        for (const auto& p : players) {
            if (p.position == i) cout << "[" << p.name << "]";
        }
        cout << " | Owner: " << (board[i].owner.empty() ? "None" : board[i].owner) << "\n";
    }

    cout << "\n Player Balances:\n";
    for (const auto& p : players) {
        cout << p.name << ": $" << p.balance << "\n";
    }
}

string MonopolyGame::getCurrentPropertyName() const {
    return board[players[currentPlayerIndex].position].name;
}

int MonopolyGame::getCurrentPropertyPrice() const {
    return board[players[currentPlayerIndex].position].price;
}
