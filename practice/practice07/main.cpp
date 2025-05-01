#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;

    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(const std::string& name, int id, double salary)
        : Employee(name, id), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2)
            << monthlySalary << std::endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(const std::string& name, int id, double rate, int hours)
        : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(const std::string& name, int id, double base, double sales, double rate)
        : Employee(name, id), baseSalary(base), salesAmount(sales), commissionRate(rate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << std::fixed << std::setprecision(2)
            << baseSalary << ", Sales: $" << salesAmount
            << ", Commission Rate: " << (commissionRate * 100) << "%"
            << ", Salary: $" << calculateSalary() << std::endl;
    }
};

int main() {
    std::ifstream file("employees.txt");
    if (!file) {
        std::cerr << "Error: Could not open employees.txt\n";
        return 1;
    }

    std::vector<Employee*> employees;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type, name;
        int id;

        if (!(iss >> type >> id >> name)) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }

        if (type == "Salaried") {
            double salary;
            if (iss >> salary) {
                employees.push_back(new SalariedEmployee(name, id, salary));
            }
            else {
                std::cerr << "Invalid salaried employee data: " << line << std::endl;
            }
        }
        else if (type == "Hourly") {
            double rate;
            int hours;
            if (iss >> rate >> hours) {
                employees.push_back(new HourlyEmployee(name, id, rate, hours));
            }
            else {
                std::cerr << "Invalid hourly employee data: " << line << std::endl;
            }
        }
        else if (type == "Commission") {
            double base, sales, rate;
            if (iss >> base >> sales >> rate) {
                employees.push_back(new CommissionEmployee(name, id, base, sales, rate));
            }
            else {
                std::cerr << "Invalid commission employee data: " << line << std::endl;
            }
        }
        else {
            std::cerr << "Unknown employee type: " << type << std::endl;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << "\nEmployee Details:\n";
    for (const auto& emp : employees) {
        emp->displayInfo();
    }

    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}
