#include <iostream>
#include <iomanip>
#include "view.h"
#include <conio.h>     // _getch()
#include <windows.h>   // system("cls")

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

// Vẽ menu động với dấu '>'
void displayMenu(int selectedIndex) {
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
}


int getUserChoice() {
    int selected = 0;
    while (true) {
        displayMenu(selected);
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72) // UP
                selected = (selected - 1 + MENU_SIZE) % MENU_SIZE;
            else if (key == 80) // DOWN
                selected = (selected + 1) % MENU_SIZE;
        } else if (key == 13) { // ENTER
            return selected + 1; // Trả về từ 1 đến 6
        }
    }
}

void displayAccount(const Account& acc) {
    cout << left << setw(10) << acc.getAccountNumber() << setw(20) << acc.getName()
     << setw(12) << acc.getType() << setw(10) << fixed << setprecision(2) << acc.getBalance() << "\n";

}

void displayAllAccountsHeader() {
    cout << left << setw(10) << "AccNo" << setw(20) << "Name"
         << setw(12) << "Type" << setw(10) << "Balance\n";
    cout << string(52, '-') << "\n";
}

void displayNotFound() {
    cout << " Khong tim thay tai khoan.\n";
}

void displayDeleted(bool success) {
    if (success)
        cout << " Da xoa tai khoan.\n";
    else
        cout << " Khong tim thay tai khoan de xoa.\n";
}

void displayUpdated(float newBalance) {
    cout << " So du moi: " << newBalance << "\n";
}
