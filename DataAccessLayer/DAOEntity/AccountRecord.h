#ifndef ACCOUNT_RECORD
#define ACCOUNT_RECORD

#include <string>
using std::string;

class AccountRecord {
    private:
        string _id;
        string _name;
        string _phoneNumber;
        string _balance;
    public:
        AccountRecord();
        AccountRecord(const string& id, const string& name, const string& phone, const string& balance);
    public:
        string getId() const;
        string getName() const;
        string getPhoneNumber() const;
        string getBalance() const;
    public:
        void setID(const string& id);
        void setName(const string& name);
        void setPhoneNumber(const string& phone);
        void setBalance(const string& balance);
};

#endif
