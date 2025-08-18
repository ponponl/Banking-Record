#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H

#include "AccountModel.h"
#include <iostream>
#include <string>
using std::cin, std::cout, std::string, std::getline;

class AccountView {
public:
    void inputCreate(AccountModel& account);
    void print(const AccountModel& account) const;
    bool inputUpdateInfo(int& id, string& newName, string& newPhone, long long& newBal, bool& updateName, bool& updatePhone, bool& updateBalance);
};

#endif
  