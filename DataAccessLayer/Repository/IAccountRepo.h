#ifndef _I_ACCOUNT_REPOSITORY_
#define _I_ACCOUNT_REPOSITORY_

#include <AccountRecord.h>
#include <string>
#include <vector>
#include <optional>

using std::string, std::vector, std::optional;

class IAccountRepository {
public:
    virtual bool addAccount(const AccountRecord& account);
    virtual void removeAccount(const string& id);
    virtual bool updateAccount(const AccountRecord& account);
public:
    virtual vector<AccountRecord> getAll() const;
    virtual optional<AccountRecord> findById(const string& id) const;
    virtual vector<AccountRecord> findByName(const string& name) const;
    virtual optional<AccountRecord> findByPhone(const string& phoneNumber) const;
};

#endif // _I_ACCOUNT_REPOSITORY_