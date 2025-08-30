#ifndef ACCOUNT_MODEL_PARSER_H
#define ACCOUNT_MODEL_PARSER_H


#include "../BusinessLayer/BusinessEntity/Account.h"
#include "../BusinessLayer/BusinessEntity/VipAccount.h"
#include "../BusinessLayer/BusinessEntity/RegularAccount.h"
#include "../BusinessLayer/BusinessEntity/CardAccount.h"
#include "../BusinessLayer/Service/CardAccountAdapter.h"
#include "../PresentationLayer/InputModel/AccountModel.h" 
#include <memory>

using std::unique_ptr, std::make_unique;

class AccountModelParser {
public:
    static std::unique_ptr<Account> toEntity(int id, const AccountModel& model) {
        if (model.getType() == AccountType::card) {
            CardAccount cardAcc(
                id,
                model.getUserId(),
                model.getCardNumber(),
                model.getExpirationDate(),
                model.getCvv(),
                model.getAvailableFunds()
            );
            return std::make_unique<CardAccountAdapter>(cardAcc);
        } else if (model.getType() == AccountType::vip || (model.getType() == AccountType::regular && model.getBalance() > 2000)) {
            return std::make_unique<VipAccount>(
                id,
                model.getUserId(),
                model.getBalance()
            );
        } else {
            return std::make_unique<RegularAccount>(
                id,
                model.getUserId(),
                model.getBalance()
            );
        }
    }

    static AccountModel toModel(const Account& entity) {
        if (auto cardAdapter = dynamic_cast<const CardAccountAdapter*>(&entity)) {
            const CardAccount& cardAcc = cardAdapter->getCardAccount();
            return AccountModel(
                cardAcc.getID(),
                cardAcc.getUserId(),
                AccountType::card,
                cardAcc.getCardNumber(),
                cardAcc.getExpirationDate(),
                cardAcc.getCvv(),
                cardAcc.getAvailableFunds()
            );
        }
        AccountType type;
        if (dynamic_cast<const VipAccount*>(&entity)) {
            type = AccountType::vip;
        } else {
            type = AccountType::regular;
        }
        return AccountModel(
            entity.getID(),
            entity.getUserId(),
            entity.getBalance(),
            type
        );
    }
};

#endif
