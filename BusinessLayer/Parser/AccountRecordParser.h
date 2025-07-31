
#pragma once
#include "../../BusinessLayer/BusinessEntity/Account.h"
#include "../../DataAccessLayer/DAOEntity/AccountRecord.h"
#include <string>

class AccountRecordParser {
public:
    static AccountRecord toDataEntity(const Account& account) {
        return AccountRecord(
            std::to_string(account.getAccountNumber()),
            account.getFirstName(),
            account.getLastName(),
            account.getPhoneNumber(),
            account.getBalance()
        );
    }

    static Account toBusinessEntity(const AccountRecord& record) {
        return Account(
            record.getAccountNumber(),
            record.getFirstName(),
            record.getLastName(),
            record.getPhoneNumber(),
            record.getBalance()
        );
    }
};


