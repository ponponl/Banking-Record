#include "App.h"
#include <iostream>

#include "./PresentationLayer/Input.h"
#include "./PresentationLayer/View.h"
#include "./BusinessLayer/AccountService.h"

using namespace std;

void App::run() {
    AccountService service;
    int choice;

    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1: {
                Account acc = inputAccount();
                service.createAccount(acc);
                break;
            }
            case 2: {
                auto all = service.getAllAccounts();
                if (all.empty()) {
                    displayNotFound();
                } else {
                    displayAllAccountsHeader();
                    for (const auto& acc : all)
                        displayAccount(acc);
                }
                break;
            }
            case 3: {
                int no = inputAccountNumber();
                Account acc;
                if (service.searchAccount(no, acc)) {
                    displayAccount(acc);
                } else {
                    displayNotFound();
                }
                break;
            }
            case 4: {
                int no = inputAccountNumber();
                float delta = inputBalanceChange();
                float newBalance;
                if (service.updateAccount(no, delta, newBalance)) {
                    displayUpdated(newBalance);
                } else {
                    displayNotFound();
                }
                break;
            }
            case 5: {
                int no = inputAccountNumber();
                bool success = service.deleteAccount(no);
                displayDeleted(success);
                break;
            }
            case 0:
                cout << "👋 Tam biet!\n";
                break;
            default:
                cout << "❗ Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}
