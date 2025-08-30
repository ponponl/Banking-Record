#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include "../InputModel/AccountModel.h"
#include "../../Utils/BalanceFormatter.h"
#include "../InputModel/UserModel.h"
#include "../../Utils/PhoneFormatter.h"

using namespace std;

class MenuView {
public:
    void displaySearchMenu(int selectedIndex);
    void displayMenu(int selectedIndex);
    void displayAllAccountsHeader();
    void displayAccount(const AccountModel& acc, const UserModel& user);
    void displayNotFound();
    void displayDeleted(bool success);
    void displayUpdated(float newBalance);
    void displayAccountCreationChoice(int selectedIndex);
};

#endif

