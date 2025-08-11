#define ACCOUNT
#ifdef ACCOUNT
#include <string>
#include <iostream>
using std::string;

class Account {
    private:
        int _id;
        string _name;
        string _phoneNumber;
        long long _balance;
    public:
        Account();
        Account(int id, const string& name, const string& phone, long long bal);
    public:
        int getID() const;
        string getName() const;
        long long getBalance() const;
        string getPhoneNumber() const;
    public:
        void setID(int id);  
        void setName(const string& name);
        void setBalance(long long bal);
        void setPhoneNumber(const string& phone);
};

#endif