#include "CardAccountAdapter.h"

CardAccountAdapter::CardAccountAdapter(const CardAccount& cardAcc)
    : Account(cardAcc.getID(), cardAcc.getHolderName(), cardAcc.getPhoneNumber(), static_cast<long long>(cardAcc.getAvailableFunds())), _cardAccount(cardAcc) {}

const CardAccount& CardAccountAdapter::getCardAccount() const { 
    return _cardAccount; 
}

int CardAccountAdapter::getID() const { 
    return _cardAccount.getID(); 
}

string CardAccountAdapter::getName() const { 
    return _cardAccount.getHolderName(); 
}

string CardAccountAdapter::getPhoneNumber() const { 
    return _cardAccount.getPhoneNumber();
}

long long CardAccountAdapter::getBalance() const { 
    return static_cast<long long>(_cardAccount.getAvailableFunds()); 
}

long long CardAccountAdapter::getLimit() const { 
    return 0; 
}
