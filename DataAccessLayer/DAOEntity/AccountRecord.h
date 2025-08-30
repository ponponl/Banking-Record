#ifndef ACCOUNT_RECORD
#define ACCOUNT_RECORD

#include <string>
using std::string;

class AccountRecord {
    private:
        string _id;
        string _userId;
        string _balance;
        string _type;
        // Card Information
        string _cardNumber;
        string _cardExpirationDate;
        string _cardCvv;
        string _cardAvailableFunds;
    public:
        AccountRecord();
        AccountRecord(const string& id, string userId, const string& balance, const string& type);
        AccountRecord(const string& id, string userId, const string& type,
                const string& cardNumber, const string& cardExpirationDate,
                const string& cardCvv, const string& cardAvailableFunds);
    public:
        string getID() const;
        string getUserId() const;
        string getBalance() const;
        string getType() const;
    public:
        // Card Information Getters
        string getCardNumber() const;
        string getCardExpirationDate() const;
        string getCardCvv() const;
        string getCardAvailableFunds() const;
    public:
        void setID(const string& id);
        void setUserId(string userId);
        void setBalance(const string& balance);
        void setType(const string& type);
    public:
        // Card Information Setters
        void setCardNumber(const string& cardNumber);
        void setCardExpirationDate(const string& cardExpirationDate);
        void setCardCvv(const string& cardCvv);
        void setCardAvailableFunds(const string& cardAvailableFunds);
};

#endif
