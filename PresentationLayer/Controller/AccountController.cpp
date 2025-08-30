#include "AccountController.h"
#include <iostream>
using namespace std;

AccountController::AccountController(MenuView& menu, InputView& input, AccountView& accView, AccountService& service)
    : menu(menu), input(input), accView(accView), service(service) {}

void AccountController::createAccount() {

    int choice = input.getAccountCreationChoice(menu);
    if (choice == -1) return; 
    UserService userService(service.getUserRepo());
    UserView userView;

    if (choice == 1) {
        // Create account for new user
        UserModel userModel;
        userView.inputUser(userModel);
        int newUserId = userService.generateNewUserId();
        userModel.setUserId(newUserId);

        // Model -> Entity
        User userEntity = UserModelParser::toEntity(userModel);
        userService.addUser(userEntity);

        // Create regular/vip account
        AccountModel accModel;
        accModel.setUserId(newUserId);
        accView.inputCreateRegularVipAccount(accModel);
        int newAccId = service.generateNewAccountID();
        cout << newAccId << "\n";
        auto accPtr = AccountModelParser::toEntity(newAccId, accModel);
        cout << "test2\n";
        service.addAccount(std::move(accPtr));
        cout << "\nSuccessfully created account for new user!\n";
    } else if (choice == 2) {
        // Open card account for user with regular account
        int userId = 0;
        cout << "Enter user ID of the user: ";
        while (!(cin >> userId)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Invalid user ID. Please re-enter: ";
        }
        cin.ignore(10000, '\n');

        // Find user by userId
        auto users = userService.getAllUsers();
        bool foundUser = false;
        for (const auto& u : users) {
            if (u.getId() == userId) {
                foundUser = true;
                break;
            }
        }
        if (!foundUser) {
            cout << "User not found with this user ID.\n";
            return;
        }

    // Create card account
    AccountModel accModel;
    accView.inputCreateCardAccount(accModel);
    accModel.setUserId(userId);
    accModel.setCardNumber(AccountService::generateCardNumber());
    cout << "Generated Card Number: " << accModel.getCardNumber() << "\n"; 
    int newAccId = service.generateNewAccountID();
    auto accPtr = AccountModelParser::toEntity(newAccId, accModel);
    service.addAccount(std::move(accPtr));
    cout << "\nSuccessfully opened card account for user ID: " << userId << "!\n";
    }
}


void AccountController::viewAllAccounts() {
    viewAllAccountsPaginated();
}

void AccountController::viewAllAccountsPaginated() {
    auto all = service.getAllAccounts();
    UserService userService(service.getUserRepo());
    auto users = userService.getAllUsers();
    std::vector<AccountModel> models;
    std::vector<UserModel> userModels;
    for (const auto& accPtr : all) {
        AccountModel accModel = AccountModelParser::toModel(*accPtr);
        models.push_back(accModel);
        // Find user for this account
        UserModel userModel;
        bool foundUser = false;
        for (const auto& u : users) {
            if (u.getId() == accModel.getUserId()) {
                userModel.setUserId(u.getId());
                userModel.setName(u.getName());
                userModel.setPhoneNumber(u.getPhoneNumber());
                foundUser = true;
                break;
            }
        }
        if (!foundUser) {
            userModel.setUserId(accModel.getUserId());
            userModel.setName("");
            userModel.setPhoneNumber("");
        }
        userModels.push_back(userModel);
    }
    const int pageSize = 10;
    int totalPages = (models.size() + pageSize - 1) / pageSize;
    int page = 0;
    while (true) {
        system("cls");
        menu.displayAllAccountsHeader();
        int totalAccounts = models.size();
        int startIdx = page * pageSize;
        int endIdx = std::min(startIdx + pageSize, totalAccounts);
        for (int i = startIdx; i < endIdx; ++i) {
            menu.displayAccount(models[i], userModels[i]);
        }
        accView.displayPaginationInfo(page, totalPages);
        cout << "Use <- (Left Arrow) and -> (Right Arrow) to navigate pages. Press Esc to exit.\n";
        int ch = 0;
        ch = _getch(); 
        if (ch == 27) break; 
        if (ch == 0 || ch == 224) {
            ch = _getch();
            if (ch == 75 && page > 0) { 
                --page;
            } else if (ch == 77 && page < totalPages - 1) { 
                ++page;
            }
        }
    }
}

void AccountController::searchAccount() {
    int searchType = input.getSearchChoice(menu);
    if (searchType == -1) return; 
    UserService userService(service.getUserRepo());
    auto users = userService.getAllUsers();
    if (searchType == 1) {
        // Search by account ID
        cout << "Enter account ID to search: ";
        int id;
        cin >> id;
        cin.ignore(10000, '\n');
        auto result = service.searchById(id);
        if (result.has_value()) {
            menu.displayAllAccountsHeader();
            AccountModel model = AccountModelParser::toModel(*result.value());
            // Find user
            UserModel userModel;
            bool foundUser = false;
            for (const auto& u : users) {
                if (u.getId() == model.getUserId()) {
                    userModel.setUserId(u.getId());
                    userModel.setName(u.getName());
                    userModel.setPhoneNumber(u.getPhoneNumber());
                    foundUser = true;
                    break;
                }
            }
            if (!foundUser) {
                userModel.setUserId(model.getUserId());
                userModel.setName("");
                userModel.setPhoneNumber("");
            }
            menu.displayAccount(model, userModel);
        } else {
            menu.displayNotFound();
        }
    } else if (searchType == 2) {
        // Search by userId
        cout << "Enter userId to search: ";
        int userId;
        cin >> userId;
        cin.ignore(10000, '\n');
        auto found = service.searchByUserId(std::to_string(userId));
        if (found.empty()) {
            menu.displayNotFound();
        } else {
            menu.displayAllAccountsHeader();
            for (const auto& accPtr : found) {
                AccountModel model = AccountModelParser::toModel(*accPtr);
                // Find user
                UserModel userModel;
                bool foundUser = false;
                for (const auto& u : users) {
                    if (u.getId() == model.getUserId()) {
                        userModel.setUserId(u.getId());
                        userModel.setName(u.getName());
                        userModel.setPhoneNumber(u.getPhoneNumber());
                        foundUser = true;
                        break;
                    }
                }
                if (!foundUser) {
                    userModel.setUserId(model.getUserId());
                    userModel.setName("");
                    userModel.setPhoneNumber("");
                }
                menu.displayAccount(model, userModel);
            }
        }
    } else if (searchType == 3) {
        // Search by username
        cout << "Enter username to search: ";
        string username;
        getline(cin, username);
        auto foundAccounts = service.searchByUserName(username, users);
        if (foundAccounts.empty()) {
            menu.displayNotFound();
        } else {
            menu.displayAllAccountsHeader();
            for (const auto& accPtr : foundAccounts) {
                AccountModel model = AccountModelParser::toModel(*accPtr);
                // Find user
                UserModel userModel;
                bool foundUser = false;
                for (const auto& u : users) {
                    if (u.getId() == model.getUserId()) {
                        userModel.setUserId(u.getId());
                        userModel.setName(u.getName());
                        userModel.setPhoneNumber(u.getPhoneNumber());
                        foundUser = true;
                        break;
                    }
                }
                if (!foundUser) {
                    userModel.setUserId(model.getUserId());
                    userModel.setName("");
                    userModel.setPhoneNumber("");
                }
                menu.displayAccount(model, userModel);
            }
        }
    } else if (searchType == 4) {
        // Search by phone number
        cout << "Enter phone number to search: ";
        string phone;
        getline(cin, phone);
        auto foundAccounts = service.searchByUserPhone(phone, users);
        if (foundAccounts.empty()) {
            menu.displayNotFound();
        } else {
            menu.displayAllAccountsHeader();
            for (const auto& accPtr : foundAccounts) {
                AccountModel model = AccountModelParser::toModel(*accPtr);
                // Find user
                UserModel userModel;
                bool foundUser = false;
                for (const auto& u : users) {
                    if (u.getId() == model.getUserId()) {
                        userModel.setUserId(u.getId());
                        userModel.setName(u.getName());
                        userModel.setPhoneNumber(u.getPhoneNumber());
                        foundUser = true;
                        break;
                    }
                }
                if (!foundUser) {
                    userModel.setUserId(model.getUserId());
                    userModel.setName("");
                    userModel.setPhoneNumber("");
                }
                menu.displayAccount(model, userModel);
            }
        }
    }
}

void AccountController::updateAccount() {
    int accountId = -1;
    accView.getAccountId(accountId);
    UserView userView;

    // Tìm tài khoản
    auto result = service.searchById(accountId);
    if (!result.has_value()) {
        menu.displayNotFound();
        return;
    }
    AccountModel accModel = AccountModelParser::toModel(*result.value());

    // Ask if user wants to update user information
    char updateUserChoice;
    do {
        cout << "Do you want to update user information? (y/n): ";
        cin >> updateUserChoice;
        cin.ignore(10000, '\n');
        if (!InputValidation::isValidYesNo(updateUserChoice)) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    } while (!InputValidation::isValidYesNo(updateUserChoice));
    if (updateUserChoice == 'y' || updateUserChoice == 'Y') {
        int userId = accModel.getUserId();
        // Tìm user
        UserService userService(service.getUserRepo());
        auto users = userService.getAllUsers();
        UserModel userModel;
        bool foundUser = false;
        for (const auto& u : users) {
            if (u.getId() == userId) {
                userModel.setUserId(u.getId());
                userModel.setName(u.getName());
                userModel.setPhoneNumber(u.getPhoneNumber());
                foundUser = true;
                break;
            }
        }
        if (!foundUser) {
            menu.displayNotFound();
            return;
        }
        string newName, newPhone;
        bool updateName = false, updatePhone = false;
        if (userView.updateUserInfo(newName, updateName, newPhone, updatePhone)) {
            if (updateName) userModel.setName(newName);
            if (updatePhone) userModel.setPhoneNumber(newPhone);
            // Convert UserModel to User entity
            User userEntity = UserModelParser::toEntity(userModel);
            userService.updateUser(userEntity);
        }
    }

    // Xác định loại tài khoản và cập nhật
    bool updateBalance = false, updateCardInfo = false;
    long long newBal = accModel.getBalance();
    string newCardNumber, newExpirationDate, newCvv;
    long long newAvailableFunds = accModel.getAvailableFunds();
    if (accModel.getType() == AccountType::regular || accModel.getType() == AccountType::vip) {
        accView.updateRegularVipAccount(newBal, updateBalance);
        if (updateBalance) accModel.setBalance(newBal);
    } else if (accModel.getType() == AccountType::card) {
        accView.updateCardAccount(newCardNumber, newExpirationDate, newCvv, newAvailableFunds, updateCardInfo);
        if (updateCardInfo) {
            accModel.setCardNumber(newCardNumber);
            accModel.setExpirationDate(newExpirationDate);
            accModel.setCvv(newCvv);
            accModel.setAvailableFunds(newAvailableFunds);
        }
    }

    // Cập nhật tài khoản
    auto accPtr = AccountModelParser::toEntity(accModel.getID(), accModel);
    bool success = service.editAccount(*accPtr);
    if (success) {
        cout << "\nUpdate done!\n";
    } else {
        menu.displayNotFound();
    }
}

void AccountController::deleteAccount() {
    cout << "Enter account ID to delete: ";
    int id;
    cin >> id;
    bool success = service.deleteAccount(id);
    menu.displayDeleted(success);
}

void AccountController::exitApp() {
    cout << "Exiting program.\n";
}
