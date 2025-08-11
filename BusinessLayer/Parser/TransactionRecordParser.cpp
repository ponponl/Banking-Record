#include "TransactionRecordParser.h"

Transaction TransactionRecordParser::toBusinessEntity(const TransactionRecord& record) {
    int accountId = stoi(record.getAccountId());
    long long amount = stoll(record.getAmount());
    return Transaction(accountId, record.getType(), amount, record.getTimestamp());
}

TransactionRecord TransactionRecordParser::toDaoEntity(const Transaction& transaction) {
    return TransactionRecord(
        to_string(transaction.getAccountId()),
        transaction.getType(),
        to_string(transaction.getAmount()),
        transaction.getTimestamp()
    );
}
