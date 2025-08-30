#pragma once
#include <string>
using std::string;

class User {
    private:
        int _userId;
        string _name;
        string _phoneNumber;
    public:
        User(int id, const string& name, const string& phone);
    public:
        int getId() const;
        string getName() const;
        string getPhoneNumber() const;
    public:
        void setId(int id);
        void setName(const string& name);
        void setPhoneNumber(const string& phone);
    public:
        bool hasName(const string& name) const { return _name == name; }
};
