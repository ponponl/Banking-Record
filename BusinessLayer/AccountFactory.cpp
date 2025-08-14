#include "AccountFactory.h"
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

using std::string;

std::unique_ptr<Account> AccountFactory::createFrom(const AccountRecord& rec) {
    const int id = std::stoi(rec.getId());
    long long bal = 0;
    try {
        bal = std::stoll(rec.getBalance());
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid balance value: " + rec.getBalance());
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Balance value out of range: " + rec.getBalance());
    }
    const string type = rec.getType();

    if (type == "vip") {
        return std::make_unique<VipAccount>(id, rec.getName(), rec.getPhoneNumber(), bal);
    }
    if (type == "regular") {
        return std::make_unique<RegularAccount>(id, rec.getName(), rec.getPhoneNumber(), bal);
    }

    throw std::runtime_error("Unknown account type: " + rec.getType());
}

std::string AccountFactory::deduceType(const Account& account) {
    if (dynamic_cast<const VipAccount*>(&account))   return "vip";
    if (dynamic_cast<const RegularAccount*>(&account)) return "regular";
    return "regular"; 
}

AccountRecord AccountFactory::toRecord(const Account& acc) {
    return AccountRecord(
        std::to_string(acc.getID()),
        acc.getName(),
        acc.getPhoneNumber(),
        std::to_string(acc.getBalance()),
        deduceType(acc)
    );
}
