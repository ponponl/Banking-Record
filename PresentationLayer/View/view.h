#pragma once
#include "../InputModel/input.h"

class DisplayView {
public:
    void displayMenu();
    void displayAccount(const Account& acc);
    void displayAllAccountsHeader();
    void displayNotFound();
    void displayDeleted(bool success);
    void displayUpdated(float newBalance);
};

class InputView {
public:
    int getUserChoice();
};
