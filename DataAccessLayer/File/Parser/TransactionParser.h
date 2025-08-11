#ifndef TRANSACTION_RECORD_PARSER_H
#define TRANSACTION_RECORD_PARSER_H

#include "../DAOEntity/TransactionRecord.h"
#include <sstream>
using std::stringstream, std::getline;

class TransactionParser {
public:
    static TransactionRecord parseFromLine(const std::string& line);
    static string toData(const TransactionRecord& record);
};

#endif
