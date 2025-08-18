#include "AccountInputValidation.h"
#include <cctype>

bool AccountInputValidation::isValidPhone(const std::string& phone) {
	if (phone.length() < 8) return false;
	for (char c : phone) {
		if (!isdigit(c)) return false;
	}
	return true;
}

bool AccountInputValidation::isValidName(const std::string& name) {
	for (char c : name) {
		if (isdigit(c)) return false;
	}
	return !name.empty();
}

bool AccountInputValidation::isValidBalance(const std::string& balanceStr) {
	if (balanceStr.empty()) return false;
	for (char c : balanceStr) {
		if (!isdigit(c)) return false;
	}
	return true;
}

