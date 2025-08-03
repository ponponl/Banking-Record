#pragma once
#include <string>
using std::string;

class AccountRecord {
private:
    string accountNumber;
    string firstName;
    string lastName;
    std::string phoneNumber;
    float balance;
public:
    AccountRecord(const string& accNo, const string& fName, const string& lName,
                  const string& phone, float bal);

    AccountRecord();

    int getAccountNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    float getBalance() const;

    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setPhoneNumber(const std::string& phone);
    void setBalance(float bal);
};
