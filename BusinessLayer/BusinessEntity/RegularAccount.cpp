#include "RegularAccount.h"
#include <iostream>

RegularAccount::RegularAccount(int id, const string& name, const string& phone, long long bal)
    : Account(id, name, phone, bal) {}

long long RegularAccount::getLimit() const {
    return 100;
}
