#include "input.h"

Account::Account() : accNo(0), name(""), type(""), balance(0.0f) {}

Account::Account(int accNo, const std::string& name, const std::string& type, float balance)
    : accNo(accNo), name(name), type(type), balance(balance) {}

int Account::getAccountNumber() const {
    return accNo;
}

std::string Account::getName() const {
    return name;
}

std::string Account::getType() const {
    return type;
}

float Account::getBalance() const {
    return balance;
}

void Account::setName(const std::string& name) {
    this->name = name;
}

void Account::setType(const std::string& type) {
    this->type = type;
}

void Account::setBalance(float balance) {
    this->balance = balance;
}
