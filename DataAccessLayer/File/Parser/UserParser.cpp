#include "UserParser.h"
#include <sstream>

#include "UserParser.h"
#include <sstream>

UserDAO UserParser::parse(const string& line) {
    std::stringstream ss(line);
    string id, name, phone;
    std::getline(ss, id, ',');
    std::getline(ss, name, ',');
    std::getline(ss, phone, ',');
    return UserDAO(id, name, phone);
}

std::vector<UserDAO> UserParser::parseMany(const std::vector<string>& lines) {
    std::vector<UserDAO> users;
    for (const auto& line : lines) {
        users.push_back(parse(line));
    }
    return users;
}

string UserParser::serialize(const UserDAO& user) {
    return user.getId() + "," + user.getName() + "," + user.getPhoneNumber();
}
