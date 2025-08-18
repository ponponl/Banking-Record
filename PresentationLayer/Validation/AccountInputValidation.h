#pragma once
#include <string>

class AccountInputValidation {
public:
	static bool isValidPhone(const std::string& phone);
	static bool isValidName(const std::string& name);
	static bool isValidBalance(const std::string& balanceStr);
};
