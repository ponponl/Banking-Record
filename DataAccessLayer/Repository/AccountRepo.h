#ifndef ACCOUNT_REPO
#define ACCOUNT_REPO

#include "IAccountRepo.h"
#include "../File/FileHandle/FileReader.h"
#include "../File/FileHandle/FileWriter.h"
#include "../File/Parser/AccountParser.h"

using std::nullopt;

class AccountRepository : public IAccountRepository {
    private:
        string _filePath;
    public:
        AccountRepository(const string& filePath);
    public:
        bool addAccount(const AccountRecord& account) override;
        void removeAccount(const string& id) override;
        bool updateAccount(const AccountRecord& account) override;
    public:
        vector<AccountRecord> getAll() const override; 
        optional<AccountRecord> findById(const string& id) const override;
        vector<AccountRecord> findByUserId(const string& userId) const;
};

#endif
