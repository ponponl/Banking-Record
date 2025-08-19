#include "AccountView.h"

bool AccountView::inputUpdateInfo(int& id, string& newName, string& newPhone, long long& newBal, bool& updateName, bool& updatePhone, bool& updateBalance) {
        cout << "Nhap ID tai khoan can cap nhat: ";
        if (!(cin >> id)) {
            cin.clear(); cin.ignore(10000, '\n');
            return false;
        }
        cin.ignore(10000, '\n');

        updateName = updatePhone = updateBalance = false;
        char choice;
        cout << "Ban co muon cap nhat ten? (y/n): ";
        cin >> choice; 
        cin.ignore(10000, '\n');
        if (choice == 'y' || choice == 'Y') {
            while (true) {
                cout << "Nhap ten moi: ";
                getline(cin, newName);
                if (!AccountInputValidation::isValidName(newName)) {
                    cout << "Ten khong duoc chua so. Vui long nhap lai!\n";
                    continue;
                }
                updateName = true;
                break;
            }
        }

        cout << "Ban co muon cap nhat so dien thoai? (y/n): ";
        cin >> choice; 
        cin.ignore(10000, '\n');
        if (choice == 'y' || choice == 'Y') {
            while (true) {
                cout << "Nhap so dien thoai moi: ";
                getline(cin, newPhone);
                auto result = AccountInputValidation::validatePhone(newPhone);
                if (!result) {
                    cout << result.error() << " Vui long nhap lai!\n";
                    continue;
                }
                updatePhone = true;
                break;
            }
        }

        cout << "Ban co muon cap nhat so du? (y/n): ";
        cin >> choice; 
        cin.ignore(10000, '\n');
        if (choice == 'y' || choice == 'Y') {
            string balanceStr;
            while (true) {
                cout << "Nhap so du moi: ";
                getline(cin, balanceStr);
                if (!AccountInputValidation::isValidBalance(balanceStr)) {
                    cout << "So du phai la so. Vui long nhap lai!\n";
                    continue;
                }
                newBal = std::stoll(balanceStr);
                updateBalance = true;
                break;
            }
        }
    return true;
}

void AccountView::inputCreate(AccountModel& account) {
    string name, phone, balanceStr;
    long long balance = 0;

    while (true) {
        cout << "Enter name: ";
        getline(cin, name);
        if (!AccountInputValidation::isValidName(name)) {
            cout << "Ten khong duoc chua so. Vui long nhap lai!\n";
            continue;
        }
        break;
    }

    while (true) {
        cout << "Enter phone: ";
        getline(cin, phone);
        auto result = AccountInputValidation::validatePhone(phone);
        if (!result) {
            cout << result.error() << " Vui long nhap lai!\n";
            continue;
        }
        break;
    }

    while (true) {
        cout << "Enter balance: ";
        getline(cin, balanceStr);
        if (!AccountInputValidation::isValidBalance(balanceStr)) {
            cout << "So du phai la so. Vui long nhap lai!\n";
            continue;
        }
        balance = std::stoll(balanceStr);
        break;
    }

    account.setName(name);
    account.setPhoneNumber(phone);
    account.setBalance(balance);
}

void AccountView::print(const AccountModel& account) const {
    cout << "Name: " << account.getName()
         << "\nPhone: " << account.getPhoneNumber()
         << "\nBalance: " << account.getBalance() << "\n";
}
