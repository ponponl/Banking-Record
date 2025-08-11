#include "TransactionRepo.h"

TransactionRepository::TransactionRepository(const string& filePath)
    : _filePath(filePath) {}

vector<TransactionRecord> TransactionRepository::getAll() const {
    FileReader reader(_filePath);
    std::vector<std::string> lines = reader.getAllLines();
    std::vector<TransactionRecord> result;

    for (const auto& line : lines) {
        if (line.empty()) continue;
        TransactionRecord record = TransactionParser::parseFromLine(line);
        result.push_back(record);
    }
    return result;
}

vector<TransactionRecord> TransactionRepository::findByAccountId(const string &accountId) const {
    vector<TransactionRecord> result;
    auto all = getAll();

    for (const auto& acc : all) {
        if (acc.getAccountId().find(accountId) != std::string::npos) {
            result.push_back(acc);
        }
    }

    return result;
}

vector<TransactionRecord> TransactionRepository::findByDate(const string &date) const {
    vector<TransactionRecord> result;
    auto all = getAll();

    for (const auto& acc : all) {
        if (acc.getTimestamp().find(date) != std::string::npos) {
            result.push_back(acc);
        }
    }

    return result;
}

bool TransactionRepository::addTransaction(const TransactionRecord& Transaction) {
    FileWriter writer = FileWriter(_filePath);
    auto line = TransactionParser::toData(Transaction);
    writer.writeLine(line);
}

