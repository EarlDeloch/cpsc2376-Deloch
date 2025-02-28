#include <iostream>
#include <vector>


//function that prints main menu
void printMenu() {
  std::cout << "\nMain Menu:\n";
  std::cout << "1. Add element to vector\n";
  std::cout << "2. Print vector\n";
  std::cout << "3. Double vector\n";
  std::cout << "4. Find sum of vector\n";
  std::cout << "5. Print multiples of a number\n";
std::cout << "6. Exit\n";
std::cout << "Enter your choice: ";

}

//function that adds a number to the vector
void addItem(std::vector<int>& userVec) {
  int userNum;
  std::cout << "Enter a number to add: ";
  std::cin >> userNum;
  userVec.push_back(userNum);
  std::cout << userNum << "added to the vector.\n";

}
//function that prints the vector
void printVector(const std::vector<int>& userVec) {
  if (userVec.empty()) {
    std::cout << "The vector is empty.\n";
    return;
  }
  std::cout << "Vector elements: ";
  for (int userNum : userVec) {
    std::cout << userNum << " ";
  }
  std::cout << std::endl;
}
//function that doubles the elements in the vector
void doubleVector(std::vector<int>& userVec) {
  for (int& userNum : userVec) {
    userNum *= 2;
  }
  std::cout << "All elements in the vector have been doubled.\n;
}
//function that adds all elements of vector
void findSum(const std::vector<int>& userVec) {
  int sum = 0;
  for (int userNum : userVec) {
    sum += userNum;
  }
  std::cout << "The sum of the vector element is: " << sum << std::endl;
}
//function that prints multiples of user number found in vecotr
void printMultiples(const std::vector<int>& userVec) {
  if (userVec.empty()) {
    std::cout << "The vector is empty\n";
    return;

  }

  //getting user number for multiples
  int value;
  std::cout << "Enter a number to find multiples of: ";
  std::cin >> value;

  //finding and printing multiples
  std::cout << "Multiples of " << value << ": ";
  bool found = false;
  for (int userNum : userVec) {
    if (userNum % value == 0) {
      std::cout << userNum << " ";
      found = true;

    }
  }
  if (!found) {
    std::cout << "None found.";
  }
  std::cout << std::endl;
}


int main() {

}
