#include "Account.h"
#include <sstream>
#include <iomanip>

// Constructors
Account::Account(int accNo, const std::string& fName, const std::string& lName, double bal)
    : accountNumber(accNo), firstName(fName), lastName(lName), balance(bal) {}

Account::Account() : accountNumber(0), firstName(""), lastName(""), balance(0.0) {}

// Getters
int Account::getAccountNumber() const { return accountNumber; }
std::string Account::getFirstName() const { return firstName; }
std::string Account::getLastName() const { return lastName; }
double Account::getBalance() const { return balance; }

// Setters
void Account::setFirstName(const std::string& fName) { firstName = fName; }
void Account::setLastName(const std::string& lName) { lastName = lName; }
void Account::setBalance(double bal) { balance = bal; }

// Display
void Account::display() const {
    std::cout << "Account #" << accountNumber << ": " << firstName << " " << lastName
              << " | Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}
