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
        int _userId;
        AccountType _type;
        long long _balance;
        //Card account fields
        string _cardNumber;
        string _expirationDate;
        string _cvv;
        long long _availableFunds;
    public:
        AccountModel();
        AccountModel(int id, int userId, long long balance, AccountType type);
        AccountModel(int id, int userId, AccountType type,
                     const string& cardNumber, const string& expirationDate,
                     const string& cvv, long long availableFunds);
    public:
        int getID() const;
        int getUserId() const;
        AccountType getType() const;
        long long getBalance() const;
    public:
        // Card account fields
        string getCardNumber() const;
        string getExpirationDate() const;
        string getCvv() const;
        long long getAvailableFunds() const;
    public:
        void setUserId(int userId);
        void setBalance(long long balance);
        void setType(AccountType type);
    public:
        // Card account fields
        void setCardNumber(const string& cardNumber);
        void setExpirationDate(const string& expirationDate);
        void setCvv(const string& cvv);
        void setAvailableFunds(long long availableFunds);
};

#endif 
