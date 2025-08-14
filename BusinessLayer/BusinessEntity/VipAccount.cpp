#include "VipAccount.h"
#include <iostream>

VipAccount::VipAccount(int id, const string& name, const string& phone, long long bal)
    : Account(id, name, phone, bal) {}

long long VipAccount::getLimit() const {
    return 2000;
}


