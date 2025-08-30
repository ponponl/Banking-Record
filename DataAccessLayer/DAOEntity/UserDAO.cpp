#include "UserDAO.h"

UserDAO::UserDAO(string id, const string& n, const string& phone)
	: _userId(id), _name(n), _phoneNumber(phone) {}

string UserDAO::getId() const {
	return _userId;
}

void UserDAO::setId(string id) {
	_userId = id;
}

string UserDAO::getName() const {
	return _name;
}

void UserDAO::setName(const string& n) {
	_name = n;
}

string UserDAO::getPhoneNumber() const {
	return _phoneNumber;
}

void UserDAO::setPhoneNumber(const string& phone) {
	_phoneNumber = phone;
}
