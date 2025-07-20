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

    if (tokens.size() >= 4) {
        int accNo = std::stoi(tokens[0]);
        double bal = std::stod(tokens[3]);
        return AccountRecord(accNo, tokens[1], tokens[2], bal);
    }
    return AccountRecord();
}


std::string Parser::serializeAccount(const AccountRecord& record) {
    return std::to_string(record.getAccountNumber()) + "," +
           record.getFirstName() + "," +
           record.getLastName() + "," +
           std::to_string(record.getBalance());
}
