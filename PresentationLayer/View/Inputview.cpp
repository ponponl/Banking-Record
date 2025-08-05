#include <iostream>
#include <iomanip>
#include "view.h"
#include <conio.h>
#include <windows.h>

using namespace std;

string menuItems[] = {
    "Tao tai khoan moi",
    "Hien thi danh sach tai khoan",
    "Tim tai khoan theo so",
    "Cap nhat tai khoan (nap/rut tien)",
    "Xoa tai khoan",
    "Thoat"
};
const int MENU_SIZE = sizeof(menuItems) / sizeof(menuItems[0]);

// ================= DisplayView =================

void DisplayView::displayMenu() {
    static int selectedIndex = 0;
    while (true) {
        system("cls");
        cout << "\n===== He Thong Quan Ly Tai Khoan Ngan Hang =====\n\n";
        for (int i = 0; i < MENU_SIZE; ++i) {
            if (i == selectedIndex)
                cout << " > ";
            else
                cout << "   ";
            cout << (i + 1) << ". " << menuItems[i] << "\n";
        }
        cout << "\nSu dung ↑ ↓ de chon, nhan Enter de tiep tuc.\n";

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) // UP
                selectedIndex = (selectedIndex - 1 + MENU_SIZE) % MENU_SIZE;
            else if (key == 80) // DOWN
                selectedIndex = (selectedIndex + 1) % MENU_SIZE;
        } else if (key == 13) {
            break;
        }
    }
}

void DisplayView::displayAllAccountsHeader() {
    cout << "+----------+--------------------+------------+----------+\n";
    cout << "| AccNo    | Name               | Type       | Balance  |\n";
    cout << "+----------+--------------------+------------+----------+\n";
}

void DisplayView::displayAccount(const Account& acc) {
    cout << "| " << left << setw(9) << acc.getAccountNumber()
         << "| " << setw(19) << acc.getName()
         << "| " << setw(11) << acc.getType()
         << "| " << right << setw(9) << fixed << setprecision(2) << acc.getBalance()
         << " |\n";
}

void DisplayView::displayNotFound() {
    cout << "\nKhong tim thay tai khoan.\n";
}

void DisplayView::displayDeleted(bool success) {
    if (success)
        cout << "\nDa xoa tai khoan.\n";
    else
        cout << "\nKhong tim thay tai khoan de xoa.\n";
}

void DisplayView::displayUpdated(float newBalance) {
    cout << "\nSo du moi: " << fixed << setprecision(2) << newBalance << "\n";
}

int InputView::getUserChoice() {
    int selected = 0;
    while (true) {
        system("cls");
        cout << "\n===== He Thong Quan Ly Tai Khoan Ngan Hang =====\n\n";
        for (int i = 0; i < MENU_SIZE; ++i) {
            if (i == selected)
                cout << " > ";
            else
                cout << "   ";
            cout << (i + 1) << ". " << menuItems[i] << "\n";
        }
        cout << "\nSu dung ↑ ↓ de chon, nhan Enter de tiep tuc.\n";

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) // UP
                selected = (selected - 1 + MENU_SIZE) % MENU_SIZE;
            else if (key == 80) // DOWN
                selected = (selected + 1) % MENU_SIZE;
        } else if (key == 13) {
            return selected + 1;
        }
    }
}

float InputView::getWithdrawAmount() {
    float amount;
    cout << "\nNhap so tien muon rut: ";
    while (!(cin >> amount) || amount <= 0) {
        cout << "So tien khong hop le. Vui long nhap lai: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return amount;
}
