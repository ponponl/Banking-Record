#ifndef _I_ACCOUNT_REPOSITORY_
#define _I_ACCOUNT_REPOSITORY_

#include "../../DataAccessLayer/DAOEntity/AccountRecord.h"
#include <string>
#include <vector>
#include <optional>

using std::string, std::vector, std::optional;

class IAccountRepository {
public:
    virtual bool addAccount(const AccountRecord& account) = 0;
    virtual void removeAccount(const string& id) = 0;
    virtual bool updateAccount(const AccountRecord& account) = 0;
public:
    virtual vector<AccountRecord> getAll() const = 0;
    virtual optional<AccountRecord> findById(const string& id) const = 0;
    virtual vector<AccountRecord> findByName(const string& name) const = 0;
    virtual optional<AccountRecord> findByPhone(const string& phoneNumber) const = 0;
};

#endif // _I_ACCOUNT_REPOSITORY_