#include "VipAccount.h"
#include <iostream>

VipAccount::VipAccount(int id, int userId, long long bal)
    : Account(id, userId, bal) {}

long long VipAccount::getLimit() const {
    return 2000;
}


