#ifndef TRANSACTION_RECORD_H
#define TRANSACTION_RECORD_H

#include <string>
using std::string;

class TransactionRecord {
private:
    string _accountId;
    string _type;
    string _amount;
    string _timestamp;
public:
    TransactionRecord();
    TransactionRecord(const string& accountId, const string& type, const string& amount, const string& timestamp);
public:
    string getAccountId() const;
    string getType() const;
    string getAmount() const;
    string getTimestamp() const;
public:
    void setAccountId(const string& id);
    void setType(const string& type);
    void setAmount(const string& amount);
    void setTimestamp(const string& timestamp);
};

#endif 
