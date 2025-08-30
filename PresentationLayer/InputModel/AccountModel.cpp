#include "AccountModel.h"
#include <iostream>

AccountModel::AccountModel()
    : _id(0),
      _userId(0),
      _balance(0),
      _type(AccountType::regular),
      _cardNumber(""),
      _expirationDate(""),
      _cvv(""),
      _availableFunds(0.0)
{}

AccountModel::AccountModel(int id, int userId, long long balance, AccountType type)
    : _id(id),
      _userId(userId),
      _balance(balance),
      _type(type)
{}

AccountModel::AccountModel(int id, int userId, AccountType type,
                           const string& cardNumber, const string& expirationDate,
                           const string& cvv, long long availableFunds)
    : _id(id),
      _userId(userId),
      _type(AccountType::card),
      _cardNumber(cardNumber),
      _expirationDate(expirationDate),
      _cvv(cvv),
      _availableFunds(availableFunds)
{}

int AccountModel::getID() const {
    return _id;
}

int AccountModel::getUserId() const {
    return _userId;
}

long long AccountModel::getBalance() const {
    return _balance;
}

AccountType AccountModel::getType() const {
    return _type;
}

string AccountModel::getCardNumber() const {
    return _cardNumber;
}

string AccountModel::getExpirationDate() const {
    return _expirationDate;
}

string AccountModel::getCvv() const {
    return _cvv;
}

long long AccountModel::getAvailableFunds() const {
    return _availableFunds;
}

void AccountModel::setUserId(int userId) {
    _userId = userId;
}

void AccountModel::setBalance(long long balance) {
    _balance = balance;
}

void AccountModel::setType(AccountType type) {
    _type = type;
}

void AccountModel::setCardNumber(const string& cardNumber) {
    _cardNumber = cardNumber;
}

void AccountModel::setExpirationDate(const string& expirationDate) {
    _expirationDate = expirationDate;
}

void AccountModel::setCvv(const string& cvv) {
    _cvv = cvv;
}

void AccountModel::setAvailableFunds(long long availableFunds) {
    _availableFunds = availableFunds;
}
