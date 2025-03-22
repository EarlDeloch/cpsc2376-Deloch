#include <iostream>
#include <fstream> //This library handles file input and output
#include <iomanip> //fixed and setprecision(2) are manipulators from <iomanip>

using namespace std; //preemptively using std

const string BALANCE_FILE = "balance.txt"; //declaring file

double getBalance() {   // Function to get the current balance from the file
    ifstream file(BALANCE_FILE); //Checks for file
    double balance = 100.0; // Default balance if file does not exist
    if (file) { //If statement makes sure file exists
        file >> balance;
    }
    else {
        // Create file with initial balance
        ofstream outFile(BALANCE_FILE); //Opens to create balance file
        if (!outFile) { //Checks to make sure it was created
            cerr << "Error: Unable to create balance file." << endl; //throws error if not created
            exit(1); //Ends program
        }
        outFile << fixed << setprecision(2) << balance; /*fixed sets setprecision to control only the total amount of digits after the decimal. Without fixed, setprecision controls he total number of digits in the entire number*/
        outFile.close(); //Closes the instance of ofstream that edited the balance file
    }
    if (!file) { //If there is a file and the file cannot be opened, this statement closes the program.
        cerr << "Error: Unable to open balance file." << endl;
        exit(1);
    }
    file.close(); //Ensures file is closed properly
    return balance; //returns balance to caller
}

// Function to update the balance in the file
void updateBalance(double newBalance) { //declares function to update balance and variable for updating
    ofstream file(BALANCE_FILE); //Establishes file writing
    if (!file) { //lets the user know if theres a problem opening the file
        cerr << "Error: Unable to update balance file." << endl;
        exit(1);
    }
    file << fixed << setprecision(2) << newBalance; //saves new balance with required formatting
    file.close(); //proper close
}

// Function to deposit money
void deposit(double amount) { //declares function to add money to account
    if (amount <= 0) { //Ensures the user enters a valid deposit amount
        cout << "Invalid deposit amount." << endl; //
        return;
    }
    double balance = getBalance(); //declares balance variable for before the deposit
    balance += amount; //adds deposit to balance
    updateBalance(balance); //calls updatebalance function to replace balance
    cout << "Deposited: $" << amount << endl; //lets user know deposit was successfull
    cout << "New Balance: $" << balance << endl;
}

// Function to withdraw money
void withdraw(double amount) { //declares withdraw function
    double balance = getBalance(); //declares the balance from before withdrawal
    if (amount <= 0) { //if statement denying invalid inputs
        cout << "Invalid withdrawal amount." << endl;
        return;
    }
    if (amount > balance) { //if statement denying overdraft
        cout << "Insufficient funds." << endl;
        return;
    }
    balance -= amount; // subtracting old amount and updating balance
    updateBalance(balance);
    cout << "Withdrawn: $" << amount << endl;//Displaying related amounts
    cout << "New Balance: $" << balance << endl;
}

// Function to display the balance
void checkBalance() { //declares function to display balance
    double balance = getBalance(); //calls function to retrieve balance from file
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl; //displays balance at fixed precsion
}
//Main function displaying menu options over and over until exit
int main() {
    int choice; //declares choice that user will input
    double amount; //declares variable for user to enter amount to deposit or withdraw

    while (true) { //menu while loop
        cout << "\nBank Account Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) { //menu if statemnts
            checkBalance();
        }
        else if (choice == 2) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            deposit(amount);
        }
        else if (choice == 3) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            withdraw(amount);
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
