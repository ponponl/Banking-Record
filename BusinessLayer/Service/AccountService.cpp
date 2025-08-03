#include "AccountService.h"
#include <iostream>
#include <iomanip>

AccountService::AccountService(const std::string &filePath) : repo(filePath) {}

void AccountService::addAccount(Account &account)
{
    int newId = generateNewAccountID(); // Sửa: int, không phải string
    account.setAccountNumber(newId);    // OK vì accountNumber là int
    AccountRecord record = AccountRecordParser::toDataEntity(account);
    repo.save(record);
}

std::vector<Account> AccountService::getAllAccounts()
{
    std::vector<AccountRecord> records = repo.getAll();
    std::vector<Account> accounts;
    for (const auto &record : records)
    {
        accounts.push_back(AccountRecordParser::toBusinessEntity(record));
    }
    return accounts;
}

bool AccountService::editAccount(const Account &account)
{
    auto found = repo.findById(account.getAccountNumber());
    if (found)
    {
        AccountRecord record = AccountRecordParser::toDataEntity(account);
        repo.update(record);
        return true;
    }
    return false;
}

bool AccountService::deleteAccount(int id)
{
    auto found = repo.findById(id);
    if (found)
    {
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

std::optional<Account> AccountService::searchAccountByPhone(const std::string& phoneNumber) {
    auto recordOpt = repo.findByPhone(phoneNumber);
    if (recordOpt.has_value()) {
        return AccountRecordParser::toBusinessEntity(recordOpt.value());
    }
    return std::nullopt;
}

int AccountService::generateNewAccountID()
{
    std::vector<Account> accounts = getAllAccounts();
    int maxId = 0;

    for (const auto &acc : accounts)
    {
        int id = acc.getAccountNumber(); // đã là int
        if (id > maxId)
            maxId = id;
    }

    return maxId + 1; // VD: nếu lớn nhất là 3 → trả về 4
}
