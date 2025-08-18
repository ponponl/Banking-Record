#ifndef SERVICE
#define SERVICE

#include "../BusinessEntity/Account.h"
#include "../../DataAccessLayer/Repository/AccountRepo.h"
#include "../../Mapping/AccountRecordParser.h"
#include <vector>
#include <optional>
#include <string>
#include <memory>
using std::vector, std::string, std::to_string, std::shared_ptr,
      std::optional, std::nullopt, std::unique_ptr;

class AccountService {
    private:
        shared_ptr<IAccountRepository> _repo;

    public:
        AccountService(shared_ptr<IAccountRepository> repo);

    public:
        vector<unique_ptr<Account>> getAllAccounts();
        void addAccount(std::unique_ptr<Account> account);
        bool editAccount(const Account& account);
        bool deleteAccount(int id);

    public:
        vector<unique_ptr<Account>> searchByName(const string& name);
        optional<unique_ptr<Account>> searchByPhone(const string& phoneNumber);
        optional<unique_ptr<Account>> searchById(int id);
        int generateNewAccountID();
};

#endif