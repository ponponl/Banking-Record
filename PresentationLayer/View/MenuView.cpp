#include "MenuView.h"

static string menuItems[] = {
    "Tao tai khoan moi",
    "Hien thi danh sach tai khoan",
    "Tim kiem tai khoan",
    "Cap nhat thong tin tai khoan",
    "Xoa tai khoan",
    "Thoat"
};
static const int MENU_SIZE = sizeof(menuItems) / sizeof(menuItems[0]);

void MenuView::displayMenu(int selectedIndex) {
    system("cls");
    cout << "\n===== He Thong Quan Ly Tai Khoan Ngan Hang =====\n\n";
    for (int i = 0; i < MENU_SIZE; ++i) {
        cout << (i == selectedIndex ? " > " : "   ");
        cout << (i + 1) << ". " << menuItems[i] << "\n";
    }
    cout << "\nSu dung mui ten de chon, nhan Enter de tiep tuc.\n";
}

void MenuView::displayAllAccountsHeader() {
    cout << "+----------+--------------------+----------------+----------+------------+\n";
    cout << "| AccNo    | Name               | Phone Number   | Type     | Balance    |\n";
    cout << "+----------+--------------------+----------------+----------+------------+\n";
}

void MenuView::displayAccount(const AccountModel& acc) {
    string formattedBalance = BalanceFormatter::formatCurrency(acc.getBalance(), 0);
    string typeStr = (acc.getType() == AccountType::regular ? "regular" : "vip");
    cout << "| " << left << setw(9) << acc.getID()
         << "| " << left << setw(19) << acc.getName()
         << "| " << left << setw(15) << acc.getPhoneNumber()
         << "| " << left << setw(9) << typeStr
         << "| " << left << setw(13) << formattedBalance
         << "\n";
}

void MenuView::displayNotFound() {
    cout << "\nKhong tim thay tai khoan.\n";
}

void MenuView::displayDeleted(bool success) {
    if (success)
        cout << "\nDa xoa tai khoan.\n";
    else
        cout << "\nKhong tim thay tai khoan de xoa.\n";
}

void MenuView::displayUpdated(float newBalance) {
    cout << "\nSo du moi: " << fixed << setprecision(2) << newBalance << "\n";
}

void MenuView::displaySearchMenu(int selectedIndex) {
    string searchItems[] = {
        "Tim theo ID",
        "Tim theo ten",
        "Tim theo so dien thoai"
    };
    const int SEARCH_SIZE = sizeof(searchItems) / sizeof(searchItems[0]);
    system("cls");
    cout << "\n--- Chon kieu tim kiem tai khoan ---\n\n";
    for (int i = 0; i < SEARCH_SIZE; ++i) {
        cout << (i == selectedIndex ? " > " : "   ");
        cout << (i + 1) << ". " << searchItems[i] << "\n";
    }
    cout << "\nSu dung mui ten de chon, nhan Enter de tiep tuc.\n";
}
