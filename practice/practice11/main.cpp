#include <iostream>
#include <string>
#include "Game.h"
#include "Customer.h"
#include "LendingRecord.h"
#include "CafeLendingSystem.h"

int main() {
    CafeLendingSystem system;
    int choice;

    // Preload some sample games and customers
    system.addGame(Game("Catan", "G001", 2));
    system.addGame(Game("Carcassonne", "G002", 3));
    system.addCustomer(Customer("Alice", "C001"));

    do {
        std::cout << "\n--- Board Game Café ---\n";
        std::cout << "1. View Available Games\n";
        std::cout << "2. Add Customer\n";
        std::cout << "3. Check Out Game\n";
        std::cout << "4. Return Game\n";
        std::cout << "5. View Customer Records\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        std::string name, id, gameID, dueDate;

        switch (choice) {
        case 1:
            system.showAvailableGames();
            break;

        case 2:
            std::cout << "Enter customer name: ";
            std::cin.ignore(); // Clear newline
            std::getline(std::cin, name);
            std::cout << "Enter customer ID: ";
            std::cin >> id;
            system.addCustomer(Customer(name, id));
            break;

        case 3:
            std::cout << "Enter game ID: ";
            std::cin >> gameID;
            std::cout << "Enter customer ID: ";
            std::cin >> id;
            std::cout << "Enter due date (YYYY-MM-DD): ";
            std::cin >> dueDate;
            system.checkOutGame(gameID, id, dueDate);
            break;

        case 4:
            std::cout << "Enter game ID: ";
            std::cin >> gameID;
            std::cout << "Enter customer ID: ";
            std::cin >> id;
            system.returnGame(gameID, id);
            break;

        case 5:
            std::cout << "Enter customer ID: ";
            std::cin >> id;
            system.showCustomerRecords(id);
            break;

        case 0:
            std::cout << "Goodbye!\n";
            break;

        default:
            std::cout << "Invalid option.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}

