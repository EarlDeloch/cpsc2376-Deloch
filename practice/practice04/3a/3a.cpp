#include <iostream>
#include <vector>
#include <string>

// Display menu
void showMenu() {
    std::cout << "\n1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Show Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

// Add a task
void addTask(std::vector<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::cin.ignore(); // Clear input
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added!\n";
}

// Remove task by number
void removeTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    int index;
    std::cout << "Enter task number to remove: ";
    std::cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + (index - 1));
    std::cout << "Task removed!\n";
}

// Show all tasks
void showTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks.\n";
        return;
    }

    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

int main() {
    std::vector<std::string> tasks;
    int choice = 0;

    while (choice != 4) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            removeTask(tasks);
        } else if (choice == 3) {
            showTasks(tasks);
        } else if (choice == 4) {
            std::cout << "Exiting Task Manager.\n";
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
