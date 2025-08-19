#include "AccountInputValidation.h"
#include <cctype>
#include <fstream>
#include <string>
#include <expected>
#include "../../BusinessLayer/Service/AccountService.h"

AccountService* AccountInputValidation::service = nullptr;

void AccountInputValidation::setAccountService(AccountService* servicePtr) {
    service = servicePtr;
}

std::expected<void, std::string> AccountInputValidation::validatePhone(const std::string& phone) {
    if (phone.length() < 8) {
        return std::unexpected("Phone number must be at least 8 digits.");
    }
    for (char c : phone) {
        if (!isdigit(c)) {
            return std::unexpected("Phone number must contain only digits.");
        }
    }
    if (!service) return std::unexpected("Cannot check for duplicate phone number.");
    auto accounts = service->getAllAccounts();
    for (const auto& accPtr : accounts) {
        if (accPtr && phone == accPtr->getPhoneNumber()) {
            return std::unexpected("Phone number already exists.");
        }
    }
    return {};
}

bool AccountInputValidation::isValidName(const string& name) {
	for (char c : name) {
		if (isdigit(c)) return false;
	}
	return !name.empty();
}

bool AccountInputValidation::isValidBalance(const string& balanceStr) {
	if (balanceStr.empty()) return false;
	for (char c : balanceStr) {
		if (!isdigit(c)) return false;
	}
	return true;
}

