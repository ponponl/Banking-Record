#include <iostream>
#include <string>
#include "input.h"
using namespace std;

Account inputAccount() {
    Account acc;
    cout << "Nhap so tai khoan: ";
    cin >> acc.accNo;
    cout << "Ten khach hang: ";
    cin.ignore();
    getline(cin, acc.name);
    cout << "Loai tai khoan (Saving/Current): ";
    getline(cin, acc.type);
    cout << "So tien ban dau: ";
    cin >> acc.balance;
    return acc;
}

int inputAccountNumber() {
    int no;
    cout << "Nhap so tai khoan: ";
    cin >> no;
    return no;
}

float inputBalanceChange() {
    float delta;
    cout << "Nhap thay doi (+/-): ";
    cin >> delta;
    return delta;
}
