#include "AccountModel.h"
#include <iostream>

//test
AccountModel::AccountModel() : _id(0), _balance(0), _name(""), _phoneNumber(""), _type(AccountType::regular) {}

AccountModel::AccountModel(int id, const string& name, const string& phone, long long balance, AccountType type)
    : _id(id), _name(name), _phoneNumber(phone), _balance(balance), _type(type) {}

int AccountModel::getID() const {
    return _id;
}

string AccountModel::getName() const {
    return _name;
}

string AccountModel::getPhoneNumber() const {
    return _phoneNumber;
}

long long AccountModel::getBalance() const {
    return _balance;
}

void AccountModel::setName(const string& name) {
    _name = name;
}

void AccountModel::setPhoneNumber(const string& phone) {
    _phoneNumber = phone;
}

void AccountModel::setBalance(long long balance) {
    _balance = balance;
}

AccountType AccountModel::getType() const {
    return _type;
}

void AccountModel::setType(AccountType type) {
    _type = type;
}
