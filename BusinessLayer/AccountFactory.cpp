
#include "AccountFactory.h"

unique_ptr<Account> AccountFactory::createFrom(const AccountRecord& rec) {
    const int id = stoi(rec.getID());
    const int userId = stoi(rec.getUserId());
    const string type = rec.getType();

    if (type == "vip" || type == "regular") {
        long long bal = 0;
        try {
            bal = stoll(rec.getBalance());
        } catch (const invalid_argument& e) {
            throw runtime_error("Invalid balance value: " + rec.getBalance());
        } catch (const out_of_range& e) {
            throw runtime_error("Balance value out of range: " + rec.getBalance());
        }
        if (type == "vip") {
            return make_unique<VipAccount>(id, userId, bal);
        }
        return make_unique<RegularAccount>(id, userId, bal);
    }
    if (type == "card") {
        CardAccount cardAcc(
            id,
            userId,
            rec.getCardNumber(),
            rec.getCardExpirationDate(),
            rec.getCardCvv(),
            stoll(rec.getCardAvailableFunds())
        );
        return make_unique<CardAccountAdapter>(cardAcc);
    }
    throw runtime_error("Unknown account type: " + rec.getType());
}

string AccountFactory::deduceType(const Account& account) {
    if (dynamic_cast<const VipAccount*>(&account))   return "vip";
    if (dynamic_cast<const RegularAccount*>(&account)) return "regular";
    if (dynamic_cast<const CardAccountAdapter*>(&account)) return "card";
    return "regular"; 
}

AccountRecord AccountFactory::toRecord(const Account& acc) {
    if (auto cardAdapter = dynamic_cast<const CardAccountAdapter*>(&acc)) {
        const CardAccount& cardAcc = cardAdapter->getCardAccount();
        return AccountRecord(
            to_string(cardAcc.getID()),
            to_string(cardAcc.getUserId()),
            "card",
            cardAcc.getCardNumber(),
            cardAcc.getExpirationDate(),
            cardAcc.getCvv(),
            to_string(cardAcc.getAvailableFunds())
        );
    }
    return AccountRecord(
        to_string(acc.getID()),
        to_string(acc.getUserId()),
        to_string(acc.getBalance()),
        deduceType(acc)
    );
}
