#include "AccountView.h"

void AccountView::getAccountId(int& accountId) {
    cout << "Enter account ID: ";
    while (!(cin >> accountId)) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Invalid ID. Please re-enter: ";
    }
    cin.ignore(10000, '\n');
}

bool AccountView::updateRegularVipAccount(long long& newBal, bool& updateBalance) {
    updateBalance = false;
    char choice;
    do {
        cout << "Do you want to update account balance? (y/n): ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (!InputValidation::isValidYesNo(choice)) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (!InputValidation::isValidYesNo(choice));
    if (choice == 'y' || choice == 'Y') {
        string balanceStr;
        while (true) {
            cout << "Enter new balance: ";
            getline(cin, balanceStr);
            if (!InputValidation::isValidBalance(balanceStr)) {
                cout << "Balance must be a number. Please re-enter!\n";
                continue;
            }
            newBal = std::stoll(balanceStr);
            updateBalance = true;
            break;
        }
    }
    return true;
}

bool AccountView::updateCardAccount(string& newCardNumber, string& newExpirationDate, string& newCvv, long long& newAvailableFunds, bool& updateCardInfo) {
    updateCardInfo = false;
    char choice;
    bool updatedAny = false;

    // Update card number
    do {
        cout << "Do you want to update card number? (y/n): ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (!InputValidation::isValidYesNo(choice)) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (!InputValidation::isValidYesNo(choice));
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter new card number: "; getline(cin, newCardNumber);
        updatedAny = true;
    }

    // Update expiration date
    do {
        cout << "Do you want to update expiration date (MM/YY)? (y/n): ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (!InputValidation::isValidYesNo(choice)) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (!InputValidation::isValidYesNo(choice));
    if (choice == 'y' || choice == 'Y') {
        while (true) {
            cout << "Enter new expiration date (MM/YY): "; getline(cin, newExpirationDate);
            auto result = InputValidation::validateDateMMYY(newExpirationDate);
            if (!result) {
                cout << result.error() << " Please try again!\n";
                continue;
            }
            break;
        }
        updatedAny = true;
    }

    // Update CVV
    do {
        cout << "Do you want to update CVV code? (y/n): ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (!InputValidation::isValidYesNo(choice)) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (!InputValidation::isValidYesNo(choice));
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter new CVV code: "; getline(cin, newCvv);
        updatedAny = true;
    }

    // Update available funds
    do {
        cout << "Do you want to update available funds? (y/n): ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (!InputValidation::isValidYesNo(choice)) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (!InputValidation::isValidYesNo(choice));
    if (choice == 'y' || choice == 'Y') {
        string availableFundsStr;
        while (true) {
            cout << "Enter new available funds: ";
            getline(cin, availableFundsStr);
            try {
                newAvailableFunds = std::stoll(availableFundsStr);
                break;
            } catch (...) {
                cout << "Invalid value. Please re-enter!\n";
            }
        }
        updatedAny = true;
    }

    updateCardInfo = updatedAny;
    return true;
}

void AccountView::inputCreateRegularVipAccount(AccountModel& account) {
    string balanceStr;
    long long balance = 0;
    while (true) {
        cout << "Enter balance: ";
        getline(cin, balanceStr);
        if (!InputValidation::isValidBalance(balanceStr)) {
            cout << "Balance must be a number. Please re-enter!\n";
            continue;
        }
        balance = std::stoll(balanceStr);
        break;
    }
    account.setBalance(balance);
    cout << "done\n";
}

void AccountView::inputCreateCardAccount(AccountModel& account) {
    string expirationDate, cvv;
    long long availableFunds = 0;
    while (true) {
        cout << "Enter expiration date (MM/YY): "; getline(cin, expirationDate);
        auto result = InputValidation::validateDateMMYY(expirationDate);
        if (!result) {
            cout << result.error() << " Please try again!\n";
            continue;
        }
        break;
    }
    cout << "Enter CVV code: "; getline(cin, cvv);
    cout << "Enter available funds: ";
    string availableFundsStr;
    getline(cin, availableFundsStr);
    try {
        availableFunds = std::stoll(availableFundsStr);
    } catch (...) {
        availableFunds = 0;
    }

    account = AccountModel(0, 0, AccountType::card, "", expirationDate, cvv, availableFunds);
}

void AccountView::displayAccountsPaginated(const std::vector<AccountModel>& accounts, int page, int pageSize) const {
    int totalAccounts = accounts.size();
    int totalPages = (totalAccounts + pageSize - 1) / pageSize;
    int startIdx = page * pageSize;
    int endIdx = std::min(startIdx + pageSize, totalAccounts);
    if (totalAccounts == 0) {
        cout << "No accounts to display.\n";
        return;
    }
    displayPaginationInfo(page, totalPages);
    cout << "Use <- (Left Arrow) and -> (Right Arrow) to navigate pages. Press Esc to exit.\n";
}

void AccountView::displayPaginationInfo(int page, int totalPages) const {
    cout << "Page " << (page + 1) << " of " << totalPages << "\n";
}
