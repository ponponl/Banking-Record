#include "AccountParser.h"

AccountRecord AccountParser::parseAccount(const string& line) {
    stringstream ss(line);
    string id, name, phoneNumber, balance;

    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, phoneNumber, ',');
    getline(ss, balance, ',');

    return AccountRecord(id, name, phoneNumber, balance);
}

string AccountParser::serializeAccount(const AccountRecord& record) {
    return record.getId() + "," +
           record.getName() + "," +
           record.getPhoneNumber() + "," +
           record.getBalance();
}

