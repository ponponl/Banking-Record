#ifndef ACCOUNT_FACTORY_H
#define ACCOUNT_FACTORY_H

#include <memory>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include "./Service/CardAccountAdapter.h"
#include "./BusinessEntity/Account.h"
#include "./BusinessEntity/RegularAccount.h"
#include "./BusinessEntity//VipAccount.h"
#include "../DataAccessLayer/DAOEntity/AccountRecord.h"
using std::string, std::vector, std::cout, std::cin, std::unique_ptr, std::to_string,
        std::invalid_argument, std::out_of_range, std::runtime_error, std::make_unique;

class AccountFactory {
    private:
        static string deduceType(const Account& account);
    public:
        static unique_ptr<Account> createFrom(const AccountRecord& record);
        static AccountRecord toRecord(const Account& account);
};

#endif
