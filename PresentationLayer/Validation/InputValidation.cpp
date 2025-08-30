#include "InputValidation.h"

AccountService* InputValidation::accountService = nullptr;

UserService* InputValidation::userService = nullptr;

void InputValidation::setAccountService(AccountService* servicePtr) {
    accountService = servicePtr;
}

void InputValidation::setUserService(UserService* servicePtr) {
    userService = servicePtr;
}

expected<void, string> InputValidation::validatePhone(const string& phone) {
    if (phone.empty() || phone[0] != '0') {
        return unexpected("Phone number must start with 0.");
    }
    for (char c : phone) {
        if (!isdigit(c)) {
            return unexpected("Phone number must contain only digits (0-9).");
        }
    }
    if (phone.length() < 8) {
        return unexpected("Phone number must be at least 8 digits.");
    }
    if (phone.length() > 10) {
        return unexpected("Phone number must not exceed 10 digits.");
    }
    if (!userService) return unexpected("Cannot check for duplicate phone number.");
    auto users = userService->getAllUsers();
    for (const auto& user : users) {
        if (phone == user.getPhoneNumber()) {
            return unexpected("Phone number already exists.");
        }
    }
    return {};
}


expected<void, string> InputValidation::validateName(const string& name) {
    if (name.empty()) {
        return unexpected("Name cannot be empty.");
    }
    for (char c : name) {
        if (isdigit(c)) {
            return unexpected("Name cannot contain digits.");
        }
    }
    return {};
}

bool InputValidation::isValidBalance(const string& balanceStr) {
    if (balanceStr.empty()) return false;
    for (char c : balanceStr) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool InputValidation::isValidYesNo(char input) {
    return input == 'y' || input == 'Y' || input == 'n' || input == 'N';
}

expected<void, string> InputValidation::validateDateMMYY(const string& dateStr) {
    if (dateStr.length() != 5 || dateStr[2] != '/') {
        return unexpected("Date must be in MM/YY format.");
    }
    string mm = dateStr.substr(0, 2);
    string yy = dateStr.substr(3, 2);
    if (!isdigit(mm[0]) || !isdigit(mm[1]) || !isdigit(yy[0]) || !isdigit(yy[1])) {
        return unexpected("Month and year must be digits.");
    }
    int month = std::stoi(mm);
    int year = std::stoi(yy);
    if (month < 1 || month > 12) {
        return unexpected("Month must be between 01 and 12.");
    }
    return {};
}