#ifndef SERVICE
#define SERVICE

#include "../BusinessEntity/Account.h"
#include "../../DataAccessLayer/Repository/AccountRepo.h"
#include "../Parser/AccountRecordParser.h"
#include <vector>
#include <optional>
#include <string>
using std::vector, std::string, std::to_string, std::optional, std::nullopt, std::shared_ptr;

class AccountService {
    private:
        shared_ptr<IAccountRepository> _repo;
    public:
        AccountService(shared_ptr<IAccountRepository> repo);

    public:
        vector<Account> getAllAccounts();
        void addAccount(Account& account);
        bool editAccount(const Account& account);
        bool deleteAccount(int id);

    public:
        vector<Account> searchByName(const string& name);
        optional<Account> searchByPhone(const string& phoneNumber);
};

#endif