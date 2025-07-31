#include "AccountService.h"

AccountService::AccountService(const std::string& filePath) : repo(filePath) {}

void AccountService::addAccount(const Account& account) {
    AccountRecord record = AccountRecordParser::toDataEntity(account);
    repo.save(record);
}

std::vector<Account> AccountService::getAllAccounts() {
    std::vector<AccountRecord> records = repo.getAll();
    std::vector<Account> accounts;
    for (const auto& record : records) {
        accounts.push_back(AccountRecordParser::toBusinessEntity(record));
    }
    return accounts;
}

bool AccountService::editAccount(const Account& account) {
    auto found = repo.findById(account.getAccountNumber());
    if (found) {
        AccountRecord record = AccountRecordParser::toDataEntity(account);
        repo.update(record);
        return true;
    }
    return false;
}

bool AccountService::deleteAccount(int id) {
    auto found = repo.findById(id);
    if (found) {
        repo.remove(id);
        return true;
    }
    return false;
}

std::optional<Account> AccountService::searchAccountByPhone(const std::string& phoneNumber) {
    auto recordOpt = repo.findByPhone(phoneNumber);
    if (recordOpt.has_value()) {
        return AccountRecordParser::toBusinessEntity(recordOpt.value());
    }
    return std::nullopt;
}

