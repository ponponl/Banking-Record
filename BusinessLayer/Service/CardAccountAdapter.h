#ifndef CARD_ACCOUNT_ADAPTER_H
#define CARD_ACCOUNT_ADAPTER_H

#include "../BusinessEntity/Account.h"
#include "../BusinessEntity/CardAccount.h"

class CardAccountAdapter : public Account {
    private:
        CardAccount _cardAccount;
    public:
        CardAccountAdapter(const CardAccount& cardAcc);
        const CardAccount& getCardAccount() const;
    public:
        int getID() const override;
        string getName() const override;
        string getPhoneNumber() const override;
        long long getBalance() const override;
        long long getLimit() const override;
};

#endif
