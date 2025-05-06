Board Game Café Lending System Design

Rephrased Program Specification

This program simulates a lightweight board game lending system for a local café. 
It allows staff to track the games available in the café, register customers, and manage game lending and returns. 
The system displays available games, records who has checked out what game, and when it’s due. 
It simplifies the process of lending board games and ensures inventory is kept up to date.


Nouns and Verbs

Nouns (classes)
- Game
- Customer
- LendingRecord
- Café Lending System
- Game ID
- Customer ID
- Due Date

Verbs (methods)
- Add game
- Add customer
- Check out game
- Return game
- Display available games
- Show lending records


Class Declarations

cpp
Game class
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

Customer class
class Customer {
public:
Customer(const std::string& name, const std::string& customerID);
std::string getName() const;
std::string getID() const;
private:
std::string name;
std::string customerID;
};

LendingRecord class
class LendingRecord {
public:
LendingRecord(const std::string& customerID, const std::string& gameID, const std::string& dueDate);
void displayRecord() const;
std::string getCustomerID() const;
std::string getGameID() const;
std::string getDueDate() const;
private:
std::string customerID;
std::string gameID;
std::string dueDate;
};

CafeLendingSystem class
class CafeLendingSystem {
public:
void addGame(const Game& game);
void addCustomer(const Customer& customer);
void checkOutGame(const std::string& gameID, const std::string& customerID, const std::string& dueDate);
void returnGame(const std::string& gameID, const std::string& customerID);
void showAvailableGames() const;
void showCustomerRecords(const std::string& customerID) const;
private:
std::vector<Game>
	games;
	std::vector<Customer>
		customers;
		std::vector<LendingRecord> records;
};
classDiagram
    class Game {
        +string title
        +string id
        +int totalCopies
        +int availableCopies
        +displayInfo()
        +decreaseAvailable()
        +increaseAvailable()
        +getId()
        +getTitle()
        +getAvailableCopies()
    }

    class Customer {
        +string name
        +string customerID
        +getName()
        +getID()
    }

    class LendingRecord {
        +string customerID
        +string gameID
        +string dueDate
        +displayRecord()
        +getCustomerID()
        +getGameID()
        +getDueDate()
    }

    class CafeLendingSystem {
        +addGame()
        +addCustomer()
        +checkOutGame()
        +returnGame()
        +showAvailableGames()
        +showCustomerRecords()
    }

    CafeLendingSystem --> Game : manages
    CafeLendingSystem --> Customer : registers
    CafeLendingSystem --> LendingRecord : tracks
    Customer --> LendingRecord : borrows
