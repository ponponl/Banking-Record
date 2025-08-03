#include "AccountParser.h"
#include <sstream>
#include <vector>


AccountRecord Parser::parseAccount(const std::string& line) {
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> tokens;

    while (std::getline(ss, item, ',')) {
        tokens.push_back(item);
    }

    if (tokens.size() >= 5) {
        int accNo = std::stoi(tokens[0]);
        std::string firstName = tokens[1];
        std::string lastName = tokens[2];
        std::string phoneNumber = tokens[3];
        double bal = std::stod(tokens[4]);

        return AccountRecord(std::to_string(accNo), firstName, lastName, phoneNumber, bal);
    }

    return AccountRecord();
}


std::string Parser::serializeAccount(const AccountRecord& record) {
    return std::to_string(record.getAccountNumber()) + "," +
           record.getFirstName() + "," +
           record.getLastName() + "," +
           record.getPhoneNumber() + "," +
           std::to_string(record.getBalance());
}

