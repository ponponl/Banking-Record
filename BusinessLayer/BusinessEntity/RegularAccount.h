#ifndef REGULAR_ACCOUNT_H
#define REGULAR_ACCOUNT_H

#include "Account.h"

class RegularAccount : public Account {
    public:
        RegularAccount(int id, int userId, long long bal);
    public:
        long long getLimit() const override;
};

#endif
