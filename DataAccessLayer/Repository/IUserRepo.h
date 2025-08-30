#ifndef USER_REPO_H
#define USER_REPO_H

#include <vector>
#include <optional>
#include "../DAOEntity/UserDAO.h"
using std::vector;
using std::optional;
using std::string;

class IUserRepo {
public:
    virtual vector<UserDAO> getAll() const = 0;
    virtual bool addUser(const UserDAO& user) = 0;
    virtual bool deleteUser(const string& userId) = 0;
    virtual bool updateUser(const UserDAO& user) = 0;
    virtual ~IUserRepo() = default;

};

#endif
