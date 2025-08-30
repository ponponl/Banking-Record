#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <string>
using std::string;

class UserModel {
private:
    int _userId;
    string _name;
    string _phoneNumber;
public:
    UserModel() = default;
    UserModel(int userId, const string& name, const string& phone);
public:
    int getUserId() const;
    string getName() const;
    void setName(const string& name);
public:
    void setUserId(int userId);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phone);
};

#endif
