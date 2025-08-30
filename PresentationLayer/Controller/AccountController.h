#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

#include "../View/MenuView.h"
#include "../View/InputView.h"
#include "../View/AccountView.h"
#include "../View/UserView.h"
#include "../../BusinessLayer/Service/UserService.h"
#include "../../BusinessLayer/Service/AccountService.h"
#include "../../Mapping/AccountModelParser.h"
#include "../InputModel/AccountModel.h"
#include "../InputModel/UserModel.h"
#include "../../Mapping/UserModelParser.h"
#include "../../Mapping/UserEntityParser.h"
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
        void viewAllAccountsPaginated(); 
        void searchAccount();
        void updateAccount();
        void deleteAccount();
        void exitApp();
};

#endif
