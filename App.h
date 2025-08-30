#ifndef APP_H
#define APP_H

#include <iostream>
#include <algorithm>
#include "./PresentationLayer/View/InputView.h"
#include "./PresentationLayer/View/MenuView.h"
#include "./PresentationLayer/View/AccountView.h"
#include "./BusinessLayer/Service/AccountService.h"
#include "./BusinessLayer/Service/UserService.h"
#include "./DataAccessLayer/Repository/AccountRepo.h"
#include "./DataAccessLayer/Repository/UserRepo.h"
#include "./PresentationLayer/InputModel/AccountModel.h"
#include "./Mapping/AccountModelParser.h"
#include <memory>

using namespace std;
class App {
public:
    int run();
};

#endif
