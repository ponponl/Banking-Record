#ifndef CARD_ACCOUNT_H
#define CARD_ACCOUNT_H

#include <string>
using std::string;

class CardAccount {
    private:
        int _id;
        string _cardNumber;
        string _holderName;
        string _expirationDate;
        string _phoneNumber;
        string _cvv;
        double _availableFunds;
    public:
        CardAccount(int id, const string& cardNum, const string& holder, const string& expDate, const string& cvvCode, double funds);
        int getID() const;
        string getCardNumber() const;
        string getHolderName() const;
        string getExpirationDate() const;
        string getCvv() const;
        double getAvailableFunds() const;
        string getPhoneNumber() const;
        void setID(int id);
        void setCardNumber(const string& cardNum);
        void setHolderName(const string& holder);
        void setExpirationDate(const string& expDate);
        void setCvv(const string& cvvCode);
        void setAvailableFunds(double funds);
        void setPhoneNumber(const string& phone);
};

#endif
