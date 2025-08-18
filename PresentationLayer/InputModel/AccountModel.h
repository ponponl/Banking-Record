#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <string>
#include <iostream>
using std::string, std::cin, std::cout, std::getline;

enum class AccountType {
    regular,
    vip
};

class AccountModel {
    private:
        int _id;  
        string _name;
        string _phoneNumber;
        AccountType _type;
        long long _balance;
    public:
        AccountModel();
        AccountModel(int id, const string& name, const string& phone, long long balance, AccountType type);
    public:
        int getID() const;
        string getName() const;
        string getPhoneNumber() const;
        AccountType getType() const;
        long long getBalance() const;
    public:
    void setName(const string& name);
    void setPhoneNumber(const string& phone);
    void setBalance(long long balance);
    void setType(AccountType type);
};

#endif 
