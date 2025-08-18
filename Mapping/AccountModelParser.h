#ifndef ACCOUNT_MODEL_PARSER_H
#define ACCOUNT_MODEL_PARSER_H

#include "../BusinessLayer/BusinessEntity/Account.h"
#include "../BusinessLayer/BusinessEntity/VipAccount.h"
#include "../BusinessLayer/BusinessEntity/RegularAccount.h"
#include "../PresentationLayer/InputModel/AccountModel.h" 
#include <memory>

using std::unique_ptr, std::make_unique;

class AccountModelParser {
public:
    static unique_ptr<Account> toEntity(int id, const AccountModel& model) {
        if (model.getBalance() > 2000) {
            return make_unique<VipAccount>(
                id,
                model.getName(),
                model.getPhoneNumber(),
                model.getBalance()
            );
        } else {
            return make_unique<RegularAccount>(
                id,
                model.getName(),
                model.getPhoneNumber(),
                model.getBalance()
            );
        }
    }

    static AccountModel toModel(const Account& entity) {
        AccountType type;

        if (dynamic_cast<const VipAccount*>(&entity)) {
            type = AccountType::vip;
        } else {
            type = AccountType::regular;
        }

        return AccountModel(
            entity.getID(),
            entity.getName(),
            entity.getPhoneNumber(),
            entity.getBalance(),
            type
        );
    }
};

#endif
