#pragma once
#include "../BusinessEntity/Account.h"
#include "../../DataAccessLayer/Repository/AccountRepo.h"
#include <vector>
#include "../Parser/AccountRecordParser.h"

class AccountService {
private:
    AccountRepository repo;
public:
    AccountService(const std::string& filePath);
    void addAccount(const Account& account);
    std::vector<Account> getAllAccounts();
    bool editAccount(const Account& account);
    bool deleteAccount(int id);
};
