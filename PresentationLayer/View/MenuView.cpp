
#include "MenuView.h"

static string menuItems[] = {
    "Create new account",
    "Display account list",
    "Search account",
    "Update account information",
    "Delete account",
    "Exit"
};
static const int MENU_SIZE = sizeof(menuItems) / sizeof(menuItems[0]);

void MenuView::displayMenu(int selectedIndex) {
    system("cls");
    cout << "\n===== Bank Account Management System =====\n\n";
    for (int i = 0; i < MENU_SIZE; ++i) {
        cout << (i == selectedIndex ? " > " : "   ");
        cout << (i + 1) << ". " << menuItems[i] << "\n";
    }
    cout << "\nUse arrow keys to select, press Enter to continue.\n";
}

void MenuView::displayAllAccountsHeader() {
    cout << "+----------+----------+--------------------+----------------+----------+------------+-----------------+-----------+-----+------------+\n";
    cout << "| AccNo    | UserID   | Name               | Phone Number   | Type     | Balance    | Card Num.       | Exp. Date | CVV | Funds      |\n";
    cout << "+----------+----------+--------------------+----------------+----------+------------+-----------------+-----------+-----+------------+\n";
}

string truncate(const string& str, size_t width) {
    if (str.length() <= width) return str;
    return str.substr(0, width - 3) + "...";
}

void MenuView::displayAccount(const AccountModel& acc, const UserModel& user) {
    string formattedBalance = (acc.getType() == AccountType::card) ? "-" : BalanceFormatter::formatCurrency(acc.getBalance(), 0);
    string formattedFunds = BalanceFormatter::formatCurrency(acc.getAvailableFunds(), 0);
    string typeStr = (
        acc.getType() == AccountType::regular ? "regular" 
        : (acc.getType() == AccountType::vip ? "vip" : "card"));
    cout << "| " << left << setw(9) << truncate(std::to_string(acc.getID()), 9)
         << "| " << left << setw(9) << truncate(std::to_string(acc.getUserId()), 9)
         << "| " << left << setw(19) << truncate(user.getName(), 19)
         << "| " << left << setw(15) << truncate(PhoneFormatter::format(user.getPhoneNumber()), 15)
         << "| " << left << setw(9) << truncate(typeStr, 9)
         << "| " << left << setw(11) << truncate(formattedBalance, 11)
         << "| " << left << setw(16) << (acc.getType() == AccountType::card ? acc.getCardNumber() : "-")
         << "| " << left << setw(10) << (acc.getType() == AccountType::card ? truncate(acc.getExpirationDate(), 10) : "-")
         << "| " << left << setw(4) << (acc.getType() == AccountType::card ? truncate(acc.getCvv(), 4) : "-")
         << "| " << left << setw(11) << (acc.getType() == AccountType::card ? truncate(formattedFunds, 11) : "-")
         << "|\n";
}

void MenuView::displayNotFound() {
    cout << "\nAccount not found.\n";
}

void MenuView::displayDeleted(bool success) {
    if (success)
        cout << "\nAccount deleted.\n";
    else
        cout << "\nAccount not found for deletion.\n";
}

void MenuView::displayUpdated(float newBalance) {
    cout << "\nNew balance: " << fixed << setprecision(2) << newBalance << "\n";
}

void MenuView::displaySearchMenu(int selectedIndex) {
    string searchItems[] = {
        "Search by ID",
        "Search by UserID",
        "Search by name",
        "Search by phone number",
        "Exit"
    };
    const int SEARCH_SIZE = sizeof(searchItems) / sizeof(searchItems[0]);
    system("cls");
    cout << "\n--- Select account search type ---\n\n";
    for (int i = 0; i < SEARCH_SIZE; ++i) {
        cout << (i == selectedIndex ? " > " : "   ");
        cout << (i + 1) << ". " << searchItems[i] << "\n";
    }
    cout << "\nUse arrow keys to select, press Enter to continue.\n\n";
}

void MenuView::displayAccountCreationChoice(int selectedIndex) {
    string creationItems[] = {
        "Create account for new user",
        "Open card account for user (already has regular account)",
        "Exit"
    };
    const int CREATION_SIZE = sizeof(creationItems) / sizeof(creationItems[0]);
    system("cls");
    cout << "\n--- Select account creation type ---\n\n";
    for (int i = 0; i < CREATION_SIZE; ++i) {
        cout << (i == selectedIndex ? " > " : "   ");
        cout << (i + 1) << ". " << creationItems[i] << "\n";
    }
    cout << "\nUse arrow keys to select, press Enter to continue.\n\n";
}