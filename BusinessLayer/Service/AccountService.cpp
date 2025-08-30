
#include "AccountService.h"

AccountService::AccountService(shared_ptr<IAccountRepository> repo, shared_ptr<IUserRepo> userRepo) {
    _repo = std::move(repo);
    _userRepo = std::move(userRepo);
}

shared_ptr<IUserRepo> AccountService::getUserRepo() const {
    return _userRepo;
}

vector<unique_ptr<Account>> AccountService::getAllAccounts()
{
    vector<AccountRecord> records = _repo->getAll();
    vector<unique_ptr<Account>> accounts;
    accounts.reserve(records.size());
    for (const auto& rec : records) {
        auto accPtr = AccountFactory::createFrom(rec);
        if (accPtr) accounts.push_back(move(accPtr));
    }
    return accounts;
}

void AccountService::addAccount(unique_ptr<Account> account) {
    account->setID(generateNewAccountID());  
    AccountRecord record = AccountFactory::toRecord(*account);
    if (!_repo->addAccount(record)) {
        throw runtime_error("Account with this ID already exists");
    }
}


bool AccountService::editAccount(const Account& account) {
    AccountRecord record = AccountFactory::toRecord(account);
    return _repo->updateAccount(record);
}

bool AccountService::deleteAccount(int id) {
    string idStr = to_string(id);
    optional<AccountRecord> found = _repo->findById(idStr);
    if (!found.has_value()) return false;

    AccountRecord acc = found.value();
    string accType = acc.getType();
    string userId = acc.getUserId();

    if (accType == "card") {
        // Just remove the card account
        _repo->removeAccount(idStr);
        return true;
    } else {
        // Remove the main account
        _repo->removeAccount(idStr);
        // Remove user
        if (_userRepo) {
            _userRepo->deleteUser(userId);
        }
        // Remove all card accounts of this user
        auto cardAccounts = _repo->findByUserId(userId);
        for (const auto& cardAcc : cardAccounts) {
            if (cardAcc.getType() == "card") {
                _repo->removeAccount(cardAcc.getID());
            }
        }
        return true;
    }
}


vector<unique_ptr<Account>> AccountService::searchByUserId(const string& userId) {
    vector<AccountRecord> records = _repo->findByUserId(userId);
    vector<unique_ptr<Account>> results;
    results.reserve(records.size());
    for (const auto& rec : records) {
        auto accPtr = AccountFactory::createFrom(rec);
        if (accPtr) results.push_back(move(accPtr));
    }
    return results;
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
    string idStr = to_string(id);
    auto found = _repo->findById(idStr);
    if (found.has_value()) {
        auto accPtr = AccountFactory::createFrom(found.value());
        if (accPtr) return move(accPtr);
    }
    return nullopt;
}

vector<unique_ptr<Account>> AccountService::searchByUserName(const string& userName, const vector<User>& users) {
    vector<int> userIds;
    for (const auto& user : users) {
        if (user.hasName(userName)) {
            userIds.push_back(user.getId());
        }
    }
    vector<unique_ptr<Account>> results;
    for (const auto& userId : userIds) {
        auto accounts = searchByUserId(to_string(userId));
        for (auto& acc : accounts) {
            results.push_back(move(acc));
        }
    }
    return results;
}

vector<unique_ptr<Account>> AccountService::searchByUserPhone(const string& phone, const vector<User>& users) {
    vector<int> userIds;
    for (const auto& user : users) {
        if (user.getPhoneNumber() == phone) {
            userIds.push_back(user.getId());
        }
    }
    vector<unique_ptr<Account>> results;
    for (const auto& userId : userIds) {
        auto accounts = searchByUserId(to_string(userId));
        for (auto& acc : accounts) {
            results.push_back(move(acc));
        }
    }
    return results;
}

string AccountService::generateCardNumber() {
    string cardNum;
    cardNum.reserve(10);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 10; ++i) {
        cardNum += '0' + (rand() % 10);
    }
    return cardNum;
}
