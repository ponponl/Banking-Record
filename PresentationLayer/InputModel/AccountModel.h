#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <string>
#include <iostream>
using std::string, std::cin, std::cout, std::getline;

enum class AccountType {
    regular,
    vip,
    card
};

class AccountModel {
    private:
        int _id;  
        string _name;
        string _phoneNumber;
        AccountType _type;
        long long _balance;
        //Card account fields
        string _cardNumber;
        string _holderName;
        string _expirationDate;
        string _cvv;
        double _availableFunds;
    public:
        AccountModel();
        AccountModel(int id, const string& name, const string& phone, long long balance, AccountType type);
        AccountModel(int id, const string& name, const string& phone, long long balance, AccountType type,
                     const string& cardNumber, const string& holderName, const string& expirationDate,
                     const string& cvv, double availableFunds);
    public:
        int getID() const;
        string getName() const;
        string getPhoneNumber() const;
        AccountType getType() const;
        long long getBalance() const;
    public:
        // Card account fields
        string getCardNumber() const;
        string getHolderName() const;
        string getExpirationDate() const;
        string getCvv() const;
        double getAvailableFunds() const;
    public:
        void setName(const string& name);
        void setPhoneNumber(const string& phone);
        void setBalance(long long balance);
        void setType(AccountType type);
    public:
        // Card account fields
        void setCardNumber(const string& cardNumber);
        void setHolderName(const string& holderName);
        void setExpirationDate(const string& expirationDate);
        void setCvv(const string& cvv);
        void setAvailableFunds(double availableFunds);
};

#endif 
