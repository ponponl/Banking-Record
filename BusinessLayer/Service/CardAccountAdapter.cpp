#include "CardAccountAdapter.h"

CardAccountAdapter::CardAccountAdapter(const CardAccount& cardAcc)
    : Account(cardAcc.getID(), cardAcc.getUserId(), static_cast<long long>(cardAcc.getAvailableFunds())), _cardAccount(cardAcc) {}

const CardAccount& CardAccountAdapter::getCardAccount() const { 
    return _cardAccount; 
}

int CardAccountAdapter::getID() const { 
    return _cardAccount.getID(); 
}

int CardAccountAdapter::getUserId() const {
    return _cardAccount.getUserId();
}

long long CardAccountAdapter::getBalance() const { 
    return static_cast<long long>(_cardAccount.getAvailableFunds()); 
}

long long CardAccountAdapter::getLimit() const { 
    return 0; 
}
