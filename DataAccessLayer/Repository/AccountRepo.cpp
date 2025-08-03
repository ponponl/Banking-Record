#include "AccountRepo.h"

AccountRepository::AccountRepository(const std::string& filePath)
    : filePath(filePath) {}

std::vector<AccountRecord> AccountRepository::getAll() {
    FileReader reader(filePath);
    std::vector<std::string> lines = reader.getAllLines();
    std::vector<AccountRecord> result;

    for (const auto& line : lines) {
        if (line.empty()) continue;
        AccountRecord record = Parser::parseAccount(line);
        result.push_back(record);
    }
    return result;
}

std::optional<AccountRecord> AccountRepository::findById(int id) {
    auto accounts = getAll();
    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() == id) {
            return acc;
        }
    }
    return std::nullopt;
}

std::vector<AccountRecord> AccountRepository::searchByName(const std::string& name) {
    std::vector<AccountRecord> result;
    auto all = getAll();

    for (const auto& acc : all) {
        if (acc.getFirstName().find(name) != std::string::npos ||
            acc.getLastName().find(name) != std::string::npos) {
            result.push_back(acc);
        }
    }

    return result;
}

std::optional<AccountRecord> AccountRepository::findByPhone(const std::string& phoneNumber) {
    auto all = getAll();
    for (const auto& acc : all) {
        if (acc.getPhoneNumber() == phoneNumber) {
            return acc;
        }
    }
    return std::nullopt;
}

std::optional<AccountRecord> AccountRepository::findByPhone(const std::string& phoneNumber) {
    auto all = getAll();
    for (const auto& acc : all) {
        if (acc.getPhoneNumber() == phoneNumber) {
            return acc;
        }
    }
    return std::nullopt;
}


void AccountRepository::save(const AccountRecord& account) {
    std::vector<AccountRecord> accounts = getAll();
    accounts.push_back(account);

    std::vector<std::string> lines;
    for (const auto& acc : accounts) {
        lines.push_back(Parser::serializeAccount(acc));
    }

    FileWriter::writeLines(filePath, lines);
}

void AccountRepository::remove(int id) {
    std::vector<AccountRecord> accounts = getAll();
    std::vector<std::string> lines;

    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() != id) {
            lines.push_back(Parser::serializeAccount(acc));
        }
    }

    FileWriter::writeLines(filePath, lines);
}

void AccountRepository::update(const AccountRecord& account) {
    std::vector<AccountRecord> accounts = getAll();
    std::vector<std::string> lines;

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == account.getAccountNumber()) {
            acc = account;
        }
        lines.push_back(Parser::serializeAccount(acc));
    }

    FileWriter::writeLines(filePath, lines);
}
