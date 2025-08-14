#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>
using std::string;
class Account {
    protected:
        int _id;
        string _name;
        string _phoneNumber;
        long long _balance;
    public:
        Account();
        Account(int id, const string& name, const string& phone, long long bal);
    public:
        virtual int getID() const;
        virtual string getName() const;
        virtual long long getBalance() const;
        virtual string getPhoneNumber() const;
    public:
        void setID(int id);  
        void setName(const string& name);
        void setBalance(long long bal);
        void setPhoneNumber(const string& phone);
    public:
        virtual long long getLimit() const = 0;
};

#endif