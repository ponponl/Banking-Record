#include "AccountRecord.h"

AccountRecord::AccountRecord() : _id(""), _name(""), _phoneNumber(""), _balance("") {}

AccountRecord::AccountRecord(const string& id, const string& name, const string& phone, const string& balance)
    : _id(id), _name(name), _phoneNumber(phone), _balance(balance) {}

string AccountRecord::getId() const {
    return _id;
}

string AccountRecord::getName() const {
    return _name;
}

string AccountRecord::getPhoneNumber() const {
    return _phoneNumber;
}

string AccountRecord::getBalance() const {
    return _balance;
}

void AccountRecord::setID(const string& id) {
    _id = id;
}

void AccountRecord::setName(const string& name) {
    _name = name;
}

void AccountRecord::setPhoneNumber(const string& phone) {
    _phoneNumber = phone;
}

void AccountRecord::setBalance(const string& balance) {
    _balance = balance;
}
