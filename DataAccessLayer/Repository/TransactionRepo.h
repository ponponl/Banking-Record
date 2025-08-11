#ifndef TRANSACTION_REPOSITORY_H
#define TRANSACTION_REPOSITORY_H

#include "../DAOEntity/TransactionRecord.h"
#include "../File/Parser/TransactionParser.h"
#include "../File/FileHandle/FileReader.h"
#include "../File/FileHandle/FileWriter.h"
#include <ITransactionRepo.h>

#include <vector>
#include <string>
#include <optional>

using std::vector, std::string, std::optional;

class TransactionRepository : public ITransactionRepository {
private:
    string _filePath;
public:
    TransactionRepository(const string& filePath);
public:
    bool addTransaction(const TransactionRecord& transaction) override;
public:
    vector<TransactionRecord> getAll() const override;
    vector<TransactionRecord> findByAccountId(const string& accountId) const override;
    vector<TransactionRecord> findByDate(const string& date) const override;
};

#endif
