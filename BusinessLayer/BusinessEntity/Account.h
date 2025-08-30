#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>
class Account {
    protected:
        int _id;
        int _userId;
        long long _balance;
    public:
        Account();
        Account(int id, int userId, long long bal);
    public:
        virtual int getID() const;
        virtual int getUserId() const;
        virtual long long getBalance() const;
    public:
        void setID(int id);  
        void setUserId(int userId);
        void setBalance(long long bal);
    public:
        virtual long long getLimit() const = 0;
};

#endif