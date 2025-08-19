
#ifndef ACCOUNT_INPUT_VALIDATION_H
#define ACCOUNT_INPUT_VALIDATION_H

#include "../../BusinessLayer/Service/AccountService.h"
#include <string>
#include <cctype>
#include <expected>
using std::string;

class AccountInputValidation {
private:
	static AccountService* service;
public:
	static void setAccountService(AccountService* servicePtr);
	static std::expected<void, std::string> validatePhone(const string& phone);
	static bool isValidName(const string& name);
	static bool isValidBalance(const string& balanceStr);
};

#endif