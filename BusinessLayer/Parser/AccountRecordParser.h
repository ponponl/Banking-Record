#pragma once
#include "../../BusinessLayer/BusinessEntity/Account.h"
#include "../../DataAccessLayer/DAOEntity/AccountRecord.h"

class AccountRecordParser {
public:
    static AccountRecord toDataEntity(const Account& account) {
        return AccountRecord(
            account.getAccountNumber(),
            account.getFirstName(),
            account.getLastName(),
            account.getBalance()
        );
    }

    static Account toBusinessEntity(const AccountRecord& record) {
        return Account(
            record.getAccountNumber(),
            record.getFirstName(),
            record.getLastName(),
            record.getBalance()
        );
    }
};

