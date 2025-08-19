#include "AccountParser.h"

AccountRecord AccountParser::parseAccount(const string& line) {
    stringstream ss(line);
    string id, name, phoneNumber, balance, type;
    string cardNumber, cardExpirationDate, cardCvv, cardAvailableFunds;

    std::getline(ss, id, ',');
    std::getline(ss, name, ',');
    std::getline(ss, phoneNumber, ',');
    std::getline(ss, balance, ',');
    std::getline(ss, type, ',');

    if (type == "card") {
        std::getline(ss, cardNumber, ',');
        std::getline(ss, cardExpirationDate, ',');
        std::getline(ss, cardCvv, ',');
        std::getline(ss, cardAvailableFunds, ',');
        return AccountRecord(id, name, phoneNumber, type,
                             cardNumber, cardExpirationDate, cardCvv, cardAvailableFunds);
    }
    return AccountRecord(id, name, phoneNumber, balance, type);
}

string AccountParser::serializeAccount(const AccountRecord& record) {
    if (record.getType() == "card") {
        return record.getID() + "," +
               record.getName() + "," +
               record.getPhoneNumber() + "," +
               record.getType() + "," +
               record.getCardNumber() + "," +
               record.getCardExpirationDate() + "," +
               record.getCardCvv() + "," +
               record.getCardAvailableFunds();
    }
    return record.getID() + "," +
           record.getName() + "," +
           record.getPhoneNumber() + "," +
           record.getBalance() + "," +
           record.getType();
}

