#pragma once
#include "../View/MenuView.h"
#include "../View/InputView.h"
#include "../View/AccountView.h"
#include "../../BusinessLayer/Service/AccountService.h"
#include "../../Mapping/AccountModelParser.h"
#include "../InputModel/AccountModel.h"
#include <memory>

class AccountController {
    private:
        MenuView& menu;
        InputView& input;
        AccountView& accView;
        AccountService& service;
    public:
        AccountController(MenuView& menu, InputView& input, AccountView& accView, AccountService& service);
        void createAccount();
        void viewAllAccounts();
        void searchAccount();
        void updateAccount();
        void deleteAccount();
        void exitApp();
};
