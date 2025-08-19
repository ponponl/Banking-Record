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
        string _type;
        // Card Information
        string _cardNumber;
        string _cardHolderName;
        string _cardExpirationDate;
        string _cardCvv;
        string _cardAvailableFunds;
    public:
        AccountRecord();
        AccountRecord(const string& id, const string& name, const string& phone, const string& balance, const string& type);
        AccountRecord(const string& id, const string& name, const string& phone, const string& balance, const string& type,
                const string& cardNumber, const string& cardHolderName, const string& cardExpirationDate,
                const string& cardCvv);
    public:
        string getID() const;
        string getName() const;
        string getPhoneNumber() const;
        string getBalance() const;
        string getType() const;
    public:
        // Card Information Getters
        string getCardNumber() const;
        string getCardHolderName() const;
        string getCardExpirationDate() const;
        string getCardCvv() const;
        string getCardAvailableFunds() const;
    public:
        void setID(const string& id);
        void setName(const string& name);
        void setPhoneNumber(const string& phone);
        void setBalance(const string& balance);
        void setType(const string& type);
    public:
        // Card Information Setters
        void setCardNumber(const string& cardNumber);
        void setCardHolderName(const string& cardHolderName);
        void setCardExpirationDate(const string& cardExpirationDate);
        void setCardCvv(const string& cardCvv);
        void setCardAvailableFunds(const string& cardAvailableFunds);
};

#endif
