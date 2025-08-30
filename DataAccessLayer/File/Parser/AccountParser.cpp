#include "AccountParser.h"

AccountRecord AccountParser::parseAccount(const string& line) {
    stringstream ss(line);
    string id, userId, balance, type;
    string cardNumber, cardExpirationDate, cardCvv, cardAvailableFunds;

    getline(ss, id, ',');
    getline(ss, userId, ',');
    getline(ss, type, ',');

    if (type == "card") {
        getline(ss, cardNumber, ',');
        getline(ss, cardExpirationDate, ',');
        getline(ss, cardCvv, ',');
        getline(ss, cardAvailableFunds, ',');
        return AccountRecord(id, userId, type,
                             cardNumber, cardExpirationDate, cardCvv, cardAvailableFunds);
    }
    getline(ss, balance, ',');
    return AccountRecord(id, userId, balance, type);
}

string AccountParser::serializeAccount(const AccountRecord& record) {
    if (record.getType() == "card") {
        return record.getID() + "," +
               record.getUserId() + "," +
               record.getType() + "," +
               record.getCardNumber() + "," +
               record.getCardExpirationDate() + "," +
               record.getCardCvv() + "," +
               record.getCardAvailableFunds();
    }
    return record.getID() + "," +
           record.getUserId() + "," +
           record.getType() + "," +
           record.getBalance();
}

