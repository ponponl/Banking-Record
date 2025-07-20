#include "AccountRecord.h"
#include <sstream>

AccountRecord::AccountRecord(int accNo, const std::string& fName, const std::string& lName, double bal)
    : accountNumber(std::to_string(accNo)), firstName(fName), lastName(lName), balance(std::to_string(bal)) {}

AccountRecord::AccountRecord() : accountNumber("0"), firstName(""), lastName(""), balance("0.0") {}

int AccountRecord::getAccountNumber() const {
    return std::stoi(accountNumber);
}

std::string AccountRecord::getFirstName() const {
    return firstName;
}

std::string AccountRecord::getLastName() const {
    return lastName;
}

double AccountRecord::getBalance() const {
    return std::stod(balance);
}

void AccountRecord::setFirstName(const std::string& fName) {
    firstName = fName;
}

void AccountRecord::setLastName(const std::string& lName) {
    lastName = lName;
}

void AccountRecord::setBalance(double bal) {
    balance = std::to_string(bal);
}
