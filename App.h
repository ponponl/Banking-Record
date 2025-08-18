#pragma once
#include <iostream>
#include <algorithm>
#include "./PresentationLayer/View/InputView.h"
#include "./PresentationLayer/View/MenuView.h"
#include "./PresentationLayer/View/AccountView.h"
#include "./BusinessLayer/Service/AccountService.h"
#include "./DataAccessLayer/Repository/AccountRepo.h"
#include "./PresentationLayer/InputModel/AccountModel.h"
#include "./Mapping/AccountModelParser.h"
#include <memory>

using namespace std;
class App {
public:
    int run();
};
