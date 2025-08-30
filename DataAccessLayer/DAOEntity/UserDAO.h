#ifndef USER_DAO_H
#define USER_DAO_H

#include <string>
using std::string;

class UserDAO {
    private:
        string _userId;
        string _name;
        string _phoneNumber;
    public:
        UserDAO(string id, const string& n, const string& phone);
    public:
        string getId() const;
        void setId(string id);
    public:
        string getName() const;
        void setName(const string& n);
    public:
        string getPhoneNumber() const;
        void setPhoneNumber(const string& phone);
};

#endif
