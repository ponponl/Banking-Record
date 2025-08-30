#define ACCOUNT_RECORD_PARSER
#ifdef ACCOUNT_RECORD_PARSER

#include "../BusinessLayer/BusinessEntity/Account.h"
#include "../DataAccessLayer/DAOEntity/AccountRecord.h"
#include "../BusinessLayer/AccountFactory.h"
#include <string>
#include <sstream>
using std::to_string, std::stoi;

class AccountRecordParser {
    public:
    static AccountRecord toDataEntity(const Account& account) {
        return AccountFactory::toRecord(account);
    }
    static std::unique_ptr<Account> toBusinessEntity(const AccountRecord& record) {
        return AccountFactory::createFrom(record);
    }
};

#endif
