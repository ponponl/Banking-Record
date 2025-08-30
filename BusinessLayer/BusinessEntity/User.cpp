#include "User.h"

User::User(int id, const string& name, const string& phone)
    : _userId(id), _name(name), _phoneNumber(phone) {}

int User::getId() const {
    return _userId;
}

void User::setId(int id) {
    _userId = id;
}

string User::getName() const {
    return _name;
}

void User::setName(const string& name) {
    _name = name;
}

string User::getPhoneNumber() const {
    return _phoneNumber;
}

void User::setPhoneNumber(const string& phone) {
    _phoneNumber = phone;
}
