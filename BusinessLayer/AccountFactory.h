#pragma once
#include <memory>
#include <string>
#include "../../BusinessLayer/BusinessEntity/Account.h"
#include "../../BusinessLayer/BusinessEntity/RegularAccount.h"
#include "../../BusinessLayer/BusinessEntity/VipAccount.h"
#include "../../DataAccessLayer/DAOEntity/AccountRecord.h"

class AccountFactory {
    private:
        static std::string deduceType(const Account& account);
    public:
        static std::unique_ptr<Account> createFrom(const AccountRecord& record);
        static AccountRecord toRecord(const Account& account);
};
