#include "UserModel.h"

UserModel::UserModel(int id, const string& name, const string& phone)
    : _userId(id), _name(name), _phoneNumber(phone) {}

int UserModel::getUserId() const {
    return _userId;
}

void UserModel::setUserId(int userId) {
    _userId = userId;
}

string UserModel::getName() const {
    return _name;
}

void UserModel::setName(const string& name) {
    _name = name;
}

string UserModel::getPhoneNumber() const {
    return _phoneNumber;
}

void UserModel::setPhoneNumber(const string& phone) {
    _phoneNumber = phone;
}
