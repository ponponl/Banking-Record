#ifndef VIP_ACCOUNT_H
#define VIP_ACCOUNT_H

#include "Account.h"

class VipAccount : public Account {
    public:
        VipAccount(int id, int userId, long long bal);
    public:
        long long getLimit() const override;
};

#endif
