#include "TransactionParser.h"

TransactionRecord TransactionParser::parseFromLine(const string& line) {
    stringstream ss(line);
    string accountId, type, amount, timestamp;

    getline(ss, accountId, ',');
    getline(ss, type, ',');
    getline(ss, amount, ',');
    getline(ss, timestamp, ',');

    return TransactionRecord(accountId, type, amount, timestamp);
}

string TransactionParser::toData(const TransactionRecord& record) {
    return record.getAccountId() + "," +
           record.getType() + "," +
           record.getAmount() + "," +
           record.getTimestamp();
}
