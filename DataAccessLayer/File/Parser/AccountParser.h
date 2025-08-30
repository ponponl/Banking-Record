#pragma once
#define ACCOUNT_PARSER_H
#ifdef ACCOUNT_PARSER_H
#include "../../DAOEntity/AccountRecord.h"
#include <string>
#include <sstream>
#include <vector>
using std::string, std::stringstream, std::vector, std::stoi, std::getline;
class AccountParser {
    public:
        static AccountRecord parseAccount(const string& line);
        static string serializeAccount(const AccountRecord& record);
};

#endif