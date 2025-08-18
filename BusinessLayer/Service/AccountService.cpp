#include "AccountService.h"
#include "../AccountFactory.h"

AccountService::AccountService(std::shared_ptr<IAccountRepository> repo) {
    _repo = std::move(repo);
}

vector<unique_ptr<Account>> AccountService::getAllAccounts()
{
    vector<AccountRecord> records = _repo->getAll();
    vector<unique_ptr<Account>> accounts;
    accounts.reserve(records.size());
    for (const auto& rec : records) {
        auto accPtr = AccountFactory::createFrom(rec);
        if (accPtr) accounts.push_back(std::move(accPtr));
    }
    return accounts;
}

void AccountService::addAccount(std::unique_ptr<Account> account) {
    account->setID(generateNewAccountID());  
    AccountRecord record = AccountFactory::toRecord(*account);
    if (!_repo->addAccount(record)) {
        throw std::runtime_error("Account with this ID already exists");
    }
}


bool AccountService::editAccount(const Account& account) {
    AccountRecord record = AccountFactory::toRecord(account);
    return _repo->updateAccount(record);
}

bool AccountService::deleteAccount(int id) {
    string idStr = std::to_string(id);
    optional<AccountRecord> found = _repo->findById(idStr);
    if (!found.has_value()) return false;
    
    _repo->removeAccount(idStr);
    return true;
}

vector<unique_ptr<Account>> AccountService::searchByName(const string& name) {
    vector<AccountRecord> records = _repo->findByName(name);
    vector<unique_ptr<Account>> results;
    results.reserve(records.size());
    for (const auto& rec : records) {
        auto accPtr = AccountFactory::createFrom(rec);
        if (accPtr) results.push_back(std::move(accPtr));
    }
    return results;
}

optional<unique_ptr<Account>> AccountService::searchByPhone(const string& phoneNumber) {
    auto found = _repo->findByPhone(phoneNumber);
    if (found.has_value()) {
        auto accPtr = AccountFactory::createFrom(found.value());
        if (accPtr) return std::move(accPtr);
    }
    return std::nullopt;
}

int AccountService::generateNewAccountID()
{
    vector<AccountRecord> records = _repo->getAll();
    int maxId = 0;

    for (const auto& record : records) {
        auto accPtr = AccountFactory::createFrom(record);
        if (accPtr && accPtr->getID() > maxId) {
            maxId = accPtr->getID();
        }
    }

    return maxId + 1;
}

optional<unique_ptr<Account>> AccountService::searchById(int id) {
    string idStr = std::to_string(id);
    auto found = _repo->findById(idStr);
    if (found.has_value()) {
        auto accPtr = AccountFactory::createFrom(found.value());
        if (accPtr) return std::move(accPtr);
    }
    return std::nullopt;
}
