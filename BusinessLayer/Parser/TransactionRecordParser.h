#ifndef TRANSACTION_PARSER_H
#define TRANSACTION_PARSER_H

#include "../../DataAccessLayer/DAOEntity/TransactionRecord.h"
#include "../BusinessLayer/BusinessEntity/Transaction.h"
#include <sstream>   
using std::stoll, std::stoi, std::to_string;

class TransactionRecordParser {
public:
    static Transaction toBusinessEntity(const TransactionRecord& record);
    static TransactionRecord toDaoEntity(const Transaction& transaction);
};

#endif
