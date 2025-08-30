#ifndef SERVICE
#define SERVICE

#include "../BusinessEntity/Account.h"
#include "../../DataAccessLayer/Repository/AccountRepo.h"
#include "../../DataAccessLayer/Repository/IUserRepo.h"
#include "../../Mapping/AccountRecordParser.h"
#include "AccountService.h"
#include "../AccountFactory.h"
#include "../BusinessEntity/User.h"

#include <vector>
#include <optional>
#include <string>
#include <memory>
using std::vector, std::string, std::to_string, std::shared_ptr,
      std::optional, std::nullopt, std::unique_ptr;

class AccountService {
    private:
        shared_ptr<IAccountRepository> _repo;
        shared_ptr<IUserRepo> _userRepo;
    public:
        AccountService(shared_ptr<IAccountRepository> repo, shared_ptr<IUserRepo> userRepo);
    public:
        vector<unique_ptr<Account>> getAllAccounts();
        void addAccount(unique_ptr<Account> account);
        bool editAccount(const Account& account);
        bool deleteAccount(int id);
    public:
        vector<unique_ptr<Account>> searchByUserId(const string& userId);
        vector<unique_ptr<Account>> searchByUserName(const string& userName, const vector<User>& users);
        vector<unique_ptr<Account>> searchByUserPhone(const string& phone, const vector<User>& users);
        optional<unique_ptr<Account>> searchById(int id);
        int generateNewAccountID();
    public:
        shared_ptr<IUserRepo> getUserRepo() const;
        static string generateCardNumber();
};

#endif