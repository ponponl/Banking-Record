#ifndef CARD_ACCOUNT_H
#define CARD_ACCOUNT_H

#include <string>
using std::string;

class CardAccount {
    private:
        int _id;
        int _userId;
        string _cardNumber;
        string _expirationDate;
        string _cvv;
        long long _availableFunds;
    public:
        CardAccount(int id, int userId, const string& cardNum, const string& expDate, const string& cvvCode, long long funds);
    public:
        int getID() const;
        int getUserId() const;
        string getCardNumber() const;
        string getExpirationDate() const;
        string getCvv() const;
        long long getAvailableFunds() const;
    public:
        void setID(int id);
        void setUserId(int userId);
        void setCardNumber(const string& cardNum);
        void setExpirationDate(const string& expDate);
        void setCvv(const string& cvvCode);
        void setAvailableFunds(long long funds);
};

#endif
