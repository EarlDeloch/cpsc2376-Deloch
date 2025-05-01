#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

using namespace std;

void printMenu() {
    cout << "Options:\n";
    cout << "1. Enter a fraction manually\n";
    cout << "2. Add a fraction\n";
    cout << "3. Subtract a fraction\n";
    cout << "4. Multiply by a fraction\n";
    cout << "5. Divide by a fraction\n";
    cout << "6. Display as Mixed Fraction\n";
    cout << "7. Clear Fraction\n";
    cout << "8. Exit\n";
}

int main() {
    Fraction currentFraction;  // Start with 0/1
    int choice;

    while (true) {
        printMenu();
        cin >> choice;

        if (choice == 1) {
            int num, den;
            cout << "Enter numerator: ";
            cin >> num;
            cout << "Enter denominator: ";
            cin >> den;
            if (!currentFraction.setFraction(num, den)) {
                cout << "Failed to set the fraction. Please try again." << endl;
            }
            else {
                cout << "Fraction set to: " << currentFraction << endl;
            }
        }
        else if (choice == 2) {
            int num, den;
            cout << "Enter numerator of fraction to add: ";
            cin >> num;
            cout << "Enter denominator of fraction to add: ";
            cin >> den;
            Fraction newFraction;
            if (!newFraction.setFraction(num, den)) {
                cout << "Failed to add the fraction. Invalid fraction input." << endl;
            }
            else {
                currentFraction = currentFraction + newFraction;
                cout << "Result: " << currentFraction << endl;
            }
        }
        else if (choice == 3) {
            int num, den;
            cout << "Enter numerator of fraction to subtract: ";
            cin >> num;
            cout << "Enter denominator of fraction to subtract: ";
            cin >> den;
            Fraction newFraction;
            if (!newFraction.setFraction(num, den)) {
                cout << "Failed to subtract the fraction. Invalid fraction input." << endl;
            }
            else {
                currentFraction = currentFraction - newFraction;
                cout << "Result: " << currentFraction << endl;
            }
        }
        else if (choice == 4) {
            int num, den;
            cout << "Enter numerator of fraction to multiply: ";
            cin >> num;
            cout << "Enter denominator of fraction to multiply: ";
            cin >> den;
            Fraction newFraction;
            if (!newFraction.setFraction(num, den)) {
                cout << "Failed to multiply the fraction. Invalid fraction input." << endl;
            }
            else {
                currentFraction = currentFraction * newFraction;
                cout << "Result: " << currentFraction << endl;
            }
        }
        else if (choice == 5) {
            int num, den;
            cout << "Enter numerator of fraction to divide: ";
            cin >> num;
            cout << "Enter denominator of fraction to divide: ";
            cin >> den;
            Fraction newFraction;
            if (!newFraction.setFraction(num, den)) {
                cout << "Failed to divide the fraction. Invalid fraction input." << endl;
            }
            else {
                currentFraction = currentFraction / newFraction;
                cout << "Result: " << currentFraction << endl;
            }
        }
        else if (choice == 6) {
            MixedFraction mf(currentFraction);
            cout << "Mixed Fraction: " << mf << endl;
        }
        else if (choice == 7) {
            currentFraction = Fraction();  // Reset to 0/1
            cout << "Fraction cleared!" << endl;
        }
        else if (choice == 8) {
            break;
        }
    }
}