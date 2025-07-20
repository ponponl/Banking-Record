#pragma once
#include <string>
using std::string;

class AccountRecord {
private:
    string accountNumber;
    string firstName;
    string lastName;
    string balance;
public:
    AccountRecord(int accNo, const std::string& fName, const std::string& lName, double bal);

    AccountRecord();

    int getAccountNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    double getBalance() const;

    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setBalance(double bal);
};
