#include "Account.h"
#include <sstream>
#include <iomanip>

// Constructors
Account::Account(int accNo, const std::string& fName, const std::string& lName, const std::string& phone, float bal)
    : accountNumber(accNo), firstName(fName), lastName(lName), phoneNumber(phone), balance(bal) {}

Account::Account() : accountNumber(0), firstName(""), lastName(""), balance(0.0) {}

// Getters
int Account::getAccountNumber() const { return accountNumber; }
std::string Account::getFirstName() const { return firstName; }
std::string Account::getLastName() const { return lastName; }
float Account::getBalance() const { return balance; }

std::string Account::getPhoneNumber() const {
    return phoneNumber;
}

// Setters
void Account::setFirstName(const std::string& fName) { firstName = fName; }
void Account::setLastName(const std::string& lName) { lastName = lName; }
void Account::setBalance(float bal) { balance = bal; }

void Account::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

// Display
void Account::display() const {
    std::cout << "Account #" << accountNumber << ": " << firstName << " " << lastName
              << " | Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}
void Account::setAccountNumber(int id) {
    accountNumber = id;
}
