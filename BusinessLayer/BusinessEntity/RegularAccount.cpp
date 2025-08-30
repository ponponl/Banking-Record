#include "RegularAccount.h"
#include <iostream>

RegularAccount::RegularAccount(int id, int userId, long long bal)
    : Account(id, userId, bal) {}

long long RegularAccount::getLimit() const {
    return 1000;
}
