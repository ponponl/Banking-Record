#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "../../DataAccessLayer/Repository/IUserRepo.h"
#include "../../DataAccessLayer/DAOEntity/UserDAO.h"
#include "../BusinessEntity/User.h"
#include "../../Mapping/UserEntityParser.h"
#include <vector>
#include <memory>
#include <string>
using std::vector, std::string, std::shared_ptr, std::stoi;

class UserService {
private:
    shared_ptr<IUserRepo> _repo;
public:
    UserService(shared_ptr<IUserRepo> repo);
    vector<User> getAllUsers() const;
    bool addUser(const User& user);
    bool deleteUser(const string& userId);
    bool updateUser(const User& user);
    int generateNewUserId() const;
};

#endif