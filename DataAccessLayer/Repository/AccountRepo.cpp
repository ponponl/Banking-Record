#include "AccountRepo.h"

AccountRepository::AccountRepository(const string& filePath)
    : _filePath(filePath) {}

vector<AccountRecord> AccountRepository::getAll() const {
    FileReader reader(_filePath);
    std::vector<std::string> lines = reader.getAllLines();
    std::vector<AccountRecord> result;

    for (const auto& line : lines) {
        if (line.empty()) continue;
        AccountRecord record = AccountParser::parseAccount(line);
        result.push_back(record);
    }
    return result;
}

std::optional<AccountRecord> AccountRepository::findById(const string& id) const {
    auto accounts = getAll();
    for (const auto& acc : accounts) {
        if (acc.getID() == id) {
            return acc;
        }
    }
    return std::nullopt;
}

std::vector<AccountRecord> AccountRepository::findByName(const std::string& name) const {
    std::vector<AccountRecord> result;
    auto all = getAll();

    for (const auto& acc : all) {
        if (acc.getName().find(name) != std::string::npos) {
            result.push_back(acc);
        }
    }

    return result;
}

std::optional<AccountRecord> AccountRepository::findByPhone(const std::string& phoneNumber) const {
    auto all = getAll();
    for (const auto& acc : all) {
        if (acc.getPhoneNumber() == phoneNumber) {
            return acc;
        }
    }
    return std::nullopt;
}

bool AccountRepository::addAccount(const AccountRecord& account) {
    FileWriter writer(_filePath, true); 
    auto line = AccountParser::serializeAccount(account);
    writer.writeLine(line);
    return true;
}

void AccountRepository::removeAccount(const string& id) {
    std::vector<AccountRecord> accounts = getAll();
    std::vector<std::string> lines;
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
    std::vector<AccountRecord> accounts = getAll();
    std::vector<std::string> lines;
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

