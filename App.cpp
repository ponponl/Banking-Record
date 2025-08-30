#include "App.h"
#include "PresentationLayer/Controller/AccountController.h"
#include "PresentationLayer/Validation/InputValidation.h"

int App::run() {
    MenuView menu;
    InputView input;
    AccountView accView;
    auto accountRepo = make_shared<AccountRepository>("DataAccessLayer/File/Data/data.txt");
    auto userRepo = make_shared<UserRepo>("DataAccessLayer/File/Data/person.txt");
    AccountService accountService(accountRepo, userRepo);
    UserService userService(userRepo);
    InputValidation::setAccountService(&accountService);
    InputValidation::setUserService(&userService);
    AccountController controller(menu, input, accView, accountService);

    while (true) {
        int choice = input.getUserChoice(menu);
        switch (choice) {
        case 1:
            controller.createAccount();
            break;
        case 2:
            controller.viewAllAccounts();
            break;
        case 3:
            controller.searchAccount();
            break;
        case 4:
            controller.updateAccount();
            break;
        case 5:
            controller.deleteAccount();
            break;
        case 6:
            controller.exitApp();
            return 0;
        }
        system("pause");
    }
}