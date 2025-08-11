#include "Account.h"

Account::Account() : _id(0), _name(""), _phoneNumber(""), _balance(0) {}

Account::Account(int id, const string& name, const string& phone, long long bal)
    : _id(id), _name(name), _phoneNumber(phone), _balance(bal) {}

int Account::getID() const { 
    return _id; 
}

string Account::getName() const {
    return _name;
}
long long Account::getBalance() const { 
    return _balance; 
}

string Account::getPhoneNumber() const {
    return _phoneNumber;
}

void Account::setName(const string& name) { 
    _name = name; 
}

void Account::setBalance(long long bal) { 
    _balance = bal; 
}

void Account::setPhoneNumber(const string& phone) {
    _phoneNumber = phone;
}

void Account::setID(int id) {
    _id = id;
}
