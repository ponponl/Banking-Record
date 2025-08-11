#include "Transaction.h"

Transaction::Transaction() : accountId(0), type(""), amount(0), timestamp("") {}

Transaction::Transaction(int accountId, const string& type, long long amount, const string& timestamp)
    : accountId(accountId), type(type), amount(amount), timestamp(timestamp) {}

int Transaction::getAccountId() const {
    return accountId;
}

string Transaction::getType() const {
    return type;
}

long long Transaction::getAmount() const {
    return amount;
}

string Transaction::getTimestamp() const {
    return timestamp;
}

void Transaction::setAccountId(int id) {
    accountId = id;
}

void Transaction::setType(const string& t) {
    type = t;
}

void Transaction::setAmount(long long a) {
    amount = a;
}

void Transaction::setTimestamp(const string& ts) {
    timestamp = ts;
}
