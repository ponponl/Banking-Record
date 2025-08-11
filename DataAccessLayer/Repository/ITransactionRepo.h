#ifndef I_TRANSACTION_REPOSITORY
#define I_TRANSACTION_REPOSITORY

#include <TransactionRecord.h>
#include <string>
#include <vector>
#include <optional>

using std::string, std::vector, std::optional;

class ITransactionRepository {
public:
    virtual bool addTransaction(const TransactionRecord& transaction);
public:
    virtual vector<TransactionRecord> getAll() const;
    virtual vector<TransactionRecord> findByAccountId(const string& accountId) const;
    virtual vector<TransactionRecord> findByDate(const string& date) const;
};

#endif // I_TRANSACTION_REPOSITORY