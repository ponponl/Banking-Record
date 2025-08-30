#ifndef ACCOUNTVIEW_H
#define ACCOUNTVIEW_H

#include "../Validation/InputValidation.h"

#include "../InputModel/AccountModel.h"
#include <iostream>
#include <string>
using std::cin, std::cout, std::string, std::getline;

class AccountView {
public:
    void inputCreateRegularVipAccount(AccountModel& account);
    void inputCreateCardAccount(AccountModel& account);
    void getAccountId(int& accountId);
    bool updateRegularVipAccount(long long& newBal, bool& updateBalance);
    bool updateCardAccount(string& newCardNumber, string& newExpirationDate, string& newCvv, long long& newAvailableFunds, bool& updateCardInfo);
    void displayAccountsPaginated(const std::vector<AccountModel>& accounts, int page, int pageSize = 10) const;
    void displayPaginationInfo(int page, int totalPages) const;
};

#endif
  