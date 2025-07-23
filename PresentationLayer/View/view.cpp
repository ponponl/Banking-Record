#include <iostream>
#include <iomanip>
#include "view.h"


using namespace std;

void displayMenu() {
    cout << "\n===== He Thong Quan Ly Tai Khoan Ngan Hang =====\n";
    cout << "1. Tao tai khoan moi\n";
    cout << "2. Hien thi danh sach tai khoan\n";
    cout << "3. Tim tai khoan theo so\n";
    cout << "4. Cap nhat tai khoan (nap/rut tien)\n";
    cout << "5. Xoa tai khoan\n";
    cout << "0. Thoat\n";
    cout << "===============================================\n";
}

int getUserChoice() {
    int choice;
    cout << "Nhap lua chon: ";
    cin >> choice;
    return choice;
}

void displayAccount(const Account& acc) {
    cout << left << setw(10) << acc.getAccountNumber()
         << setw(20) << (acc.getFirstName() + " " + acc.getLastName())
         << setw(12) << "N/A"  // nếu chưa có field "type"
         << setw(10) << fixed << setprecision(2) << acc.getBalance()
         << "\n";
}


void displayAllAccountsHeader() {
    cout << left << setw(10) << "accountNumber" << setw(20) << "Name"
         << setw(12) << "Type" << setw(10) << "Balance\n";
    cout << string(52, '-') << "\n";
}

void displayNotFound() {
    cout << "❌ Khong tim thay tai khoan.\n";
}

void displayDeleted(bool success) {
    if (success)
        cout << "✅ Da xoa tai khoan.\n";
    else
        cout << "❌ Khong tim thay tai khoan de xoa.\n";
}

void displayUpdated(float newBalance) {
    cout << "✅ So du moi: " << newBalance << "\n";
}
