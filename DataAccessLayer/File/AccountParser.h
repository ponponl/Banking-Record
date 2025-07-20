#pragma once
#include "../DAOEntity/AccountRecord.h"
#include <string>

class Parser {
public:
    static AccountRecord parseAccount(const std::string& line);
    static std::string serializeAccount(const AccountRecord& record);
};
