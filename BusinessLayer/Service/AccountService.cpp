#include "AccountService.h"
#include "../Parser/AccountRecordParser.h"

AccountService::AccountService(shared_ptr<IAccountRepository> repo) {
    _repo = std::move(repo);
}

vector<Account> AccountService::getAllAccounts()
{
    vector<AccountRecord> records = _repo->getAll();
    vector<Account> accounts;
    for (const auto& rec : records) {
        accounts.push_back(AccountRecordParser::toBusinessEntity(rec));
    }
    return accounts;
}

void AccountService::addAccount(Account& account) {
    account.setID(account.getID()); 
    AccountRecord record = AccountRecordParser::toDataEntity(account);
    if (!_repo->addAccount(record)) {
        throw std::runtime_error("Account with this ID already exists");
    }
}

bool AccountService::editAccount(const Account& account) {
    AccountRecord record = AccountRecordParser::toDataEntity(account);
    return _repo->updateAccount(record);
}

bool AccountService::deleteAccount(int id) {
    string idStr = std::to_string(id);
    optional<AccountRecord> found = _repo->findById(idStr);
    if (!found.has_value()) return false;
    
    _repo->removeAccount(idStr);
    return true;
}

vector<Account> AccountService::searchByName(const string& name) {
    vector<AccountRecord> records = _repo->findByName(name);
    vector<Account> results;
    for (const auto& rec : records) {
        results.push_back(AccountRecordParser::toBusinessEntity(rec));
    }
    return results;
}

optional<Account> AccountService::searchByPhone(const string& phoneNumber) {
    auto found = _repo->findByPhone(phoneNumber);
    if (found.has_value()) {
        return AccountRecordParser::toBusinessEntity(found.value());
    }
    return std::nullopt;
}


