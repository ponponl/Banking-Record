#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include "AccountModel.h"
#include "../../Utils/BalanceFormatter.h"

using namespace std;

class MenuView {
    public:
        void displaySearchMenu(int selectedIndex);
        void displayMenu(int selectedIndex);
        void displayAllAccountsHeader();
        void displayAccount(const AccountModel& acc);
        void displayNotFound();
        void displayDeleted(bool success);
        void displayUpdated(float newBalance);
};

