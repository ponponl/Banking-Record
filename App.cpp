
#include "App.h"

int App::run() {
    MenuView menu;
    InputView input;
    AccountView accView;
    auto repo = std::make_shared<AccountRepository>("DataAccessLayer/File/Data/data.txt");
    AccountService service(repo);

    while (true) {
        int choice = input.getUserChoice(menu);
        switch (choice) {
        case 1: {
            AccountModel accModel;
            accView.inputCreate(accModel);

            int newId = service.generateNewAccountID();
            auto accPtr = AccountModelParser::toEntity(newId, accModel); 

            service.addAccount(std::move(accPtr));

            cout << "\nTao tai khoan thanh cong!\n";
            break;
        }
        case 2: {
            auto all = service.getAllAccounts();
            if (all.empty()) {
                menu.displayNotFound();
            } else {
                menu.displayAllAccountsHeader();
                for (const auto& accPtr : all) {
                    AccountModel model = AccountModelParser::toModel(*accPtr);
                    menu.displayAccount(model);
                }
            }
            break;
        }
        case 3: {
            int searchType = input.getSearchChoice(menu);
            if (searchType == 1) { 
                cout << "Nhap ID can tim: ";
                int id;
                cin >> id;
                cin.ignore(10000, '\n');
                auto result = service.searchById(id);
                if (result.has_value()) {
                    menu.displayAllAccountsHeader();
                    AccountModel model = AccountModelParser::toModel(*result.value());
                    menu.displayAccount(model);
                } else {
                    menu.displayNotFound();
                }
            } else if (searchType == 2) { 
                cout << "Nhap ten can tim: ";
                string name;
                cin.ignore();
                getline(cin, name);
                auto found = service.searchByName(name);
                if (found.empty()) {
                    menu.displayNotFound();
                } else {
                    menu.displayAllAccountsHeader();
                    for (const auto& accPtr : found) {
                        AccountModel model = AccountModelParser::toModel(*accPtr);
                        menu.displayAccount(model);
                    }
                }
            } else if (searchType == 3) { 
                cout << "Nhap so dien thoai can tim: ";
                string phone;
                getline(cin, phone);
                auto result = service.searchByPhone(phone);
                if (result.has_value()) {
                    menu.displayAllAccountsHeader();
                    AccountModel model = AccountModelParser::toModel(*result.value());
                    menu.displayAccount(model);
                } else {
                    menu.displayNotFound();
                }
            }
            break;
        }
        case 4: {
            int id = -1;
            string newName, newPhone;
            long long newBal = -1;
            bool updateName = false, updatePhone = false, updateBalance = false;
            if (accView.inputUpdateInfo(id, newName, newPhone, newBal, updateName, updatePhone, updateBalance)) {
                auto result = service.searchById(id);
                if (!result.has_value()) {
                    menu.displayNotFound();
                } else {
                    Account& updated = *result.value();
                    if (updateName) updated.setName(newName);
                    if (updatePhone) updated.setPhoneNumber(newPhone);
                    if (updateBalance) updated.setBalance(newBal);
                    bool success = service.editAccount(updated);
                    if (success) {
                        cout << "Cap nhat thanh cong \n";
                    } else {
                        menu.displayNotFound();
                    }
                }
            } else {
                cout << "Thong tin nhap khong hop le!\n";
            }
            break;
        }
        case 5: {
            cout << "Nhap ID tai khoan can xoa: ";
            int id;
            cin >> id;
            bool success = service.deleteAccount(id);
            menu.displayDeleted(success);
            break;
        }
        case 6:
            cout << "Thoat chuong trinh.\n";
            return 0;
        }
        system("pause");
    }
}
