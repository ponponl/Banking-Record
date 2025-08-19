#include "AccountModel.h"
#include <iostream>

AccountModel::AccountModel()
        : _id(0),
            _balance(0),
            _name(""),
            _phoneNumber(""),
            _type(AccountType::regular),
            _cardNumber(""),
            _holderName(""),
            _expirationDate(""),
            _cvv(""),
            _availableFunds(0.0)
{}

AccountModel::AccountModel(int id, const string& name, const string& phone, long long balance, AccountType type)
        : _id(id),
            _name(name),
            _phoneNumber(phone),
            _balance(balance),
            _type(type),
            _cardNumber(""),
            _holderName(""),
            _expirationDate(""),
            _cvv(""),
            _availableFunds(0.0)
{}

AccountModel::AccountModel(int id, const string& name, const string& phone, long long balance, AccountType type,
                                                     const string& cardNumber, const string& holderName, const string& expirationDate,
                                                     const string& cvv, double availableFunds)
        : _id(id),
            _name(name),
            _phoneNumber(phone),
            _balance(balance),
            _type(AccountType::card),
            _cardNumber(cardNumber),
            _holderName(holderName),
            _expirationDate(expirationDate),
            _cvv(cvv),
            _availableFunds(availableFunds)
{}

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

AccountType AccountModel::getType() const { 
    return _type; 
}

string AccountModel::getCardNumber() const { 
    return _cardNumber; 
}

string AccountModel::getHolderName() const { 
    return _holderName; 
}

string AccountModel::getExpirationDate() const { 
    return _expirationDate; 
}

string AccountModel::getCvv() const { 
    return _cvv; 
}

double AccountModel::getAvailableFunds() const { 
    return _availableFunds; 
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

void AccountModel::setType(AccountType type) { 
    _type = type; 
}

void AccountModel::setCardNumber(const string& cardNumber) { 
    _cardNumber = cardNumber; 
}

void AccountModel::setHolderName(const string& holderName) { 
    _holderName = holderName; 
}

void AccountModel::setExpirationDate(const string& expirationDate) { 
    _expirationDate = expirationDate; 
}

void AccountModel::setCvv(const string& cvv) { 
    _cvv = cvv; 
}

void AccountModel::setAvailableFunds(double availableFunds) { 
    _availableFunds = availableFunds; 
}
