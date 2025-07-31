#include "AccountRecord.h"
#include <sstream>

AccountRecord::AccountRecord(const string& accNo, const string& fName, const string& lName,
                             const string& phone, float bal)
    : accountNumber(accNo), firstName(fName), lastName(lName), phoneNumber(phone), balance(bal) {}

AccountRecord::AccountRecord() : accountNumber("0"), firstName(""), lastName(""), balance(0) {}

int AccountRecord::getAccountNumber() const {
    return std::stoi(accountNumber);
}

std::string AccountRecord::getFirstName() const {
    return firstName;
}

std::string AccountRecord::getLastName() const {
    return lastName;
}

float AccountRecord::getBalance() const {
    return balance;
}

std::string AccountRecord::getPhoneNumber() const {
    return phoneNumber;
}

void AccountRecord::setFirstName(const std::string& fName) {
    firstName = fName;
}

void AccountRecord::setLastName(const std::string& lName) {
    lastName = lName;
}

void AccountRecord::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

void AccountRecord::setBalance(float bal) {
    balance = bal;
}
