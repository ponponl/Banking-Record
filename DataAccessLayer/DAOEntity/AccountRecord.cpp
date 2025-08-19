#include "AccountRecord.h"

AccountRecord::AccountRecord() {}

AccountRecord::AccountRecord(const string& id, const string& name, const string& phone, const string& balance, const string& type)
        : _id(id),
            _name(name),
            _phoneNumber(phone),
            _balance(balance),
            _type(type),
            _cardNumber(""),
            _cardHolderName(""), 
            _cardExpirationDate(""),
            _cardCvv(""),
            _cardAvailableFunds("") {}

AccountRecord::AccountRecord(const string& id, const string& name, const string& phone, const string& balance, const string& type,
                                                         const string& cardNumber, const string& cardHolderName, const string& cardExpirationDate,
                                                         const string& cardCvv)
        : _id(id),
            _name(name),
            _phoneNumber(phone),
            _balance(balance),
            _type(type),
            _cardNumber(cardNumber),
            _cardHolderName(name), 
            _cardExpirationDate(cardExpirationDate),
            _cardCvv(cardCvv),
            _cardAvailableFunds(balance) {}
string AccountRecord::getCardHolderName() const {
    return _cardHolderName;
}
void AccountRecord::setCardHolderName(const string& cardHolderName) {
    _cardHolderName = cardHolderName;
}

string AccountRecord::getID() const { 
    return _id; 
}
string AccountRecord::getName() const { 
    return _name; 
}
string AccountRecord::getPhoneNumber() const { 
    return _phoneNumber; 
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
void AccountRecord::setName(const string& name) { 
    _name = name; 
}
void AccountRecord::setPhoneNumber(const string& phone) { 
    _phoneNumber = phone; 
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
