#include "CardAccount.h"


CardAccount::CardAccount(int id, int userId, const string& cardNum, const string& expDate, const string& cvvCode, long long funds)
    : _id(id), _userId(userId), _cardNumber(cardNum), _expirationDate(expDate), _cvv(cvvCode), _availableFunds(funds) {}

int CardAccount::getID() const { 
    return _id; 
}
int CardAccount::getUserId() const {
    return _userId;
}
string CardAccount::getCardNumber() const { 
    return _cardNumber; 
}
string CardAccount::getExpirationDate() const { 
    return _expirationDate; 
}
string CardAccount::getCvv() const { 
    return _cvv; 
}
long long CardAccount::getAvailableFunds() const { 
    return _availableFunds; 
}
void CardAccount::setID(int id) { 
    _id = id; 
}
void CardAccount::setUserId(int userId) {
    _userId = userId;
}
void CardAccount::setCardNumber(const string& cardNum) { 
    _cardNumber = cardNum; 
}
void CardAccount::setExpirationDate(const string& expDate) { 
    _expirationDate = expDate; 
}
void CardAccount::setCvv(const string& cvvCode) { 
    _cvv = cvvCode; 
}
void CardAccount::setAvailableFunds(long long funds) { 
    _availableFunds = funds; 
}
