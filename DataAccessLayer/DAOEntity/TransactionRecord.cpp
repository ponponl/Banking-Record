#include "TransactionRecord.h"

TransactionRecord::TransactionRecord() : _accountId(""), _type(""), _amount(""), _timestamp("") {}

TransactionRecord::TransactionRecord(const string& accountId, const string& type, const string& amount, const string& timestamp)
    : _accountId(accountId), _type(type), _amount(amount), _timestamp(timestamp) {}

string TransactionRecord::getAccountId() const {
    return _accountId;
}

string TransactionRecord::getType() const {
    return _type;
}

string TransactionRecord::getAmount() const {
    return _amount;
}

string TransactionRecord::getTimestamp() const {
    return _timestamp;
}

void TransactionRecord::setAccountId(const string& id) {
    _accountId = id;
}

void TransactionRecord::setType(const string& type) {
    _type = type;
}

void TransactionRecord::setAmount(const string& amount) {
    _amount = amount;
}

void TransactionRecord::setTimestamp(const string& time) {
    _timestamp = time;
}
