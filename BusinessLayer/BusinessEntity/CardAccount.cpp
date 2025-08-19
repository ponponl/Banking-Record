#include "CardAccount.h"


CardAccount::CardAccount(int id, const string& cardNum, const string& holder, const string& expDate, const string& cvvCode, double funds)
    : _id(id), _cardNumber(cardNum), _holderName(holder), _expirationDate(expDate), _cvv(cvvCode), _availableFunds(funds), _phoneNumber("") {}


int CardAccount::getID() const { 
    return _id; 
}
string CardAccount::getCardNumber() const { 
    return _cardNumber; 
}
string CardAccount::getHolderName() const { 
    return _holderName; 
}
string CardAccount::getExpirationDate() const { 
    return _expirationDate; 
}
string CardAccount::getCvv() const { 
    return _cvv; 
}
double CardAccount::getAvailableFunds() const { 
    return _availableFunds; 
}
string CardAccount::getPhoneNumber() const { 
    return _phoneNumber; 
}
void CardAccount::setID(int id) { 
    _id = id; 
}
void CardAccount::setCardNumber(const string& cardNum) { 
    _cardNumber = cardNum; 
}
void CardAccount::setHolderName(const string& holder) { 
    _holderName = holder; 
}
void CardAccount::setExpirationDate(const string& expDate) { 
    _expirationDate = expDate; 
}
void CardAccount::setCvv(const string& cvvCode) { 
    _cvv = cvvCode; 
}
void CardAccount::setAvailableFunds(double funds) { 
    _availableFunds = funds; 
}
void CardAccount::setPhoneNumber(const string& phone) { 
    _phoneNumber = phone; 
}
