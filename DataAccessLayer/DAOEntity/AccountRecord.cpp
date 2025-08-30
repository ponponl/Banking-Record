#include "AccountRecord.h"

AccountRecord::AccountRecord() {}

AccountRecord::AccountRecord(const string& id, string userId, const string& balance, const string& type)
        : _id(id),
            _userId(userId),
            _balance(balance),
            _type(type),
            _cardNumber(""),
            _cardExpirationDate(""),
            _cardCvv(""),
            _cardAvailableFunds("") {}

AccountRecord::AccountRecord(const string& id, string userId, const string& type,
                            const string& cardNumber, const string& cardExpirationDate,
                            const string& cardCvv, const string& cardAvailableFunds)
        : _id(id),
            _userId(userId),
            _type(type),
            _cardNumber(cardNumber),
            _cardExpirationDate(cardExpirationDate),
            _cardCvv(cardCvv),
            _cardAvailableFunds(cardAvailableFunds) {}

string AccountRecord::getID() const { 
    return _id; 
}
string AccountRecord::getUserId() const {
    return _userId;
}
string AccountRecord::getBalance() const { 
    return _balance; 
}
string AccountRecord::getType() const { 
    return _type; 
}
string AccountRecord::getCardNumber() const { 
    return _cardNumber; 
}
string AccountRecord::getCardExpirationDate() const { 
    return _cardExpirationDate; 
}
string AccountRecord::getCardCvv() const { 
    return _cardCvv; 
}
string AccountRecord::getCardAvailableFunds() const { 
    return _cardAvailableFunds; 
} 
void AccountRecord::setID(const string& id) { 
    _id = id; 
}
void AccountRecord::setUserId(string userId) {
    _userId = userId;
}
void AccountRecord::setBalance(const string& balance) { 
    _balance = balance; 
}
void AccountRecord::setType(const string& type) { 
    _type = type; 
}
void AccountRecord::setCardNumber(const string& cardNumber) { 
    _cardNumber = cardNumber; 
}
void AccountRecord::setCardExpirationDate(const string& cardExpirationDate) { 
    _cardExpirationDate = cardExpirationDate; 
}
void AccountRecord::setCardCvv(const string& cardCvv) { 
    _cardCvv = cardCvv; 
}
void AccountRecord::setCardAvailableFunds(const string& cardAvailableFunds) { 
    _cardAvailableFunds = cardAvailableFunds; 
}
