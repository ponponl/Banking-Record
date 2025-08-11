#define ACCOUNT_RECORD_PARSER
#ifdef ACCOUNT_RECORD_PARSER

#include "../../BusinessLayer/BusinessEntity/Account.h"
#include "../../DataAccessLayer/DAOEntity/AccountRecord.h"
#include <string>
#include <sstream>
using std::to_string, std::stoi, std::stoll;

class AccountRecordParser {
    public:
        static AccountRecord toDataEntity(const Account& account) {
            return AccountRecord(
                to_string(account.getID()),
                account.getName(),
                account.getPhoneNumber(),
                to_string(account.getBalance())
            );
        }

        static Account toBusinessEntity(const AccountRecord& record) {
            return Account(
                stoi(record.getId()),
                record.getName(),
                record.getPhoneNumber(),
                stoll(record.getBalance())
            );
        }
};

#endif
