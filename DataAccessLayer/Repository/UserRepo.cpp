#include "UserRepo.h"

UserRepo::UserRepo(const string& filePath) : _filePath(filePath) {}

vector<UserDAO> UserRepo::getAll() const {
    FileReader reader(_filePath);
    vector<string> lines = reader.getAllLines();
    vector<UserDAO> users;
    for (const auto& line : lines) {
        if (line.empty()) continue;
        users.push_back(UserParser::parse(line));
    }
    return users;
}

bool UserRepo::addUser(const UserDAO& user) {
    FileWriter writer(_filePath, true);
    string line = UserParser::serialize(user);
    writer.writeLine(line);
    return true;
}

bool UserRepo::deleteUser(const string& userId) {
    vector<UserDAO> users = getAll();
    vector<string> lines;
    bool hasUser = false;
    for (const auto& user : users) {
        if (user.getId() != userId) {
            lines.push_back(UserParser::serialize(user));
        } else {
            hasUser = true;
        }
    }
    if (hasUser) {
        FileWriter::writeLines(lines, _filePath);
        return true;
    }
    return false;
}

bool UserRepo::updateUser(const UserDAO& user) {
    vector<UserDAO> users = getAll();
    bool updated = false;
    for (auto& u : users) {
        if (u.getId() == user.getId()) {
            u = user;
            updated = true;
            break;
        }
    }
    if (updated) {
        vector<string> lines;
        for (const auto& u : users) {
            lines.push_back(UserParser::serialize(u));
        }
        FileWriter::writeLines(lines, _filePath);
        return true;
    }
    return false;
}
