
#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include "../../BusinessLayer/Service/AccountService.h"
#include "../../BusinessLayer/Service/UserService.h"
#include <string>
#include <cctype>
#include <expected>
#include <fstream>
using std::string, std::unexpected, std::expected;

class InputValidation {
private:
	static AccountService* accountService;
	static UserService* userService;
public:
	static void setAccountService(AccountService* servicePtr);
	static void setUserService(UserService* servicePtr);
	static expected<void, string> validatePhone(const string& phone);
	static expected<void, string> validateName(const string& name);
	static expected<void, string> validateDateMMYY(const string& dateStr);
	static bool isValidBalance(const string& balanceStr);
	static bool isValidYesNo(char input);
};

#endif