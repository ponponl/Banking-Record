#include "Account.h"

Account::Account() : _id(0), _userId(0), _balance(0) {}

Account::Account(int id, int userId, long long bal)
    : _id(id), _userId(userId), _balance(bal) {}

int Account::getID() const { 
    return _id; 
}

int Account::getUserId() const {
    return _userId;
}

long long Account::getBalance() const { 
    return _balance; 
}

void Account::setUserId(int userId) {
    _userId = userId;
}

void Account::setBalance(long long bal) { 
    _balance = bal; 
}

void Account::setID(int id) {
    _id = id;
}
