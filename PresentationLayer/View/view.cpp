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

// Lấy lựa chọn từ người dùng
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

// Hiển thị tiêu đề bảng tài khoản
void displayAllAccountsHeader() {
    cout << "+----------+--------------------+------------+----------+\n";
    cout << "| AccNo    | Name               | Type       | Balance  |\n";
    cout << "+----------+--------------------+------------+----------+\n";
}

// Hiển thị một tài khoản theo dạng bảng có viền
void displayAccount(const Account& acc) {
    cout << "| " << left << setw(9) << acc.getAccountNumber()
         << "| " << setw(19) << acc.getName()
         << "| " << setw(11) << acc.getType()
         << "| " << right << setw(9) << fixed << setprecision(2) << acc.getBalance()
         << " |\n";
}

// Hiển thị thông báo không tìm thấy tài khoản
void displayNotFound() {
    cout << "\nKhong tim thay tai khoan.\n";
}

// Hiển thị thông báo xóa tài khoản
void displayDeleted(bool success) {
    if (success)
        cout << "\nDa xoa tai khoan.\n";
    else
        cout << "\nKhong tim thay tai khoan de xoa.\n";
}

// Hiển thị số dư mới sau khi cập nhật
void displayUpdated(float newBalance) {
    cout << "\nSo du moi: " << fixed << setprecision(2) << newBalance << "\n";
}
