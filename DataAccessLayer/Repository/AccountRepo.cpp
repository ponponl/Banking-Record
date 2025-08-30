#include "AccountRepo.h"

AccountRepository::AccountRepository(const string& filePath)
    : _filePath(filePath) {}

vector<AccountRecord> AccountRepository::getAll() const {
    FileReader reader(_filePath);
    vector<string> lines = reader.getAllLines();
    vector<AccountRecord> result;

    for (const auto& line : lines) {
        if (line.empty()) continue;
        AccountRecord record = AccountParser::parseAccount(line);
        result.push_back(record);
    }
    return result;
}

optional<AccountRecord> AccountRepository::findById(const string& id) const {
    auto accounts = getAll();
    for (const auto& acc : accounts) {
        if (acc.getID() == id) {
            return acc;
        }
    }
    return nullopt;
}

bool AccountRepository::addAccount(const AccountRecord& account) {
    FileWriter writer(_filePath, true); 
    auto line = AccountParser::serializeAccount(account);
    writer.writeLine(line);
    return true;
}

void AccountRepository::removeAccount(const string& id) {
    vector<AccountRecord> accounts = getAll();
    vector<string> lines;
    bool hasAccount = false;

    for (const auto& acc : accounts) {
        if (acc.getID() != id) {
            hasAccount = true;
            lines.push_back(AccountParser::serializeAccount(acc));
        }
    }
    if (hasAccount) {
        FileWriter::writeLines(lines, _filePath);
    }
}

bool AccountRepository::updateAccount(const AccountRecord& account) {
    vector<AccountRecord> accounts = getAll();
    vector<string> lines;
    bool hasAccount = false;

    for (auto& acc : accounts) {
        if (acc.getID() == account.getID()) {
            acc = account;
            hasAccount = true;
        }
        lines.push_back(AccountParser::serializeAccount(acc));
    }

    if (hasAccount) {
        FileWriter::writeLines(lines, _filePath);
    }
    return hasAccount;
}

vector<AccountRecord> AccountRepository::findByUserId(const string& userId) const {
    vector<AccountRecord> result;
    auto all = getAll();
    for (const auto& acc : all) {
        if (acc.getUserId() == userId) {
            result.push_back(acc);
        }
    }
    return result;
}
