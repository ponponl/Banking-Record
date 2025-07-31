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

