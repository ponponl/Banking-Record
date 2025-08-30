#ifndef USERREPO_H
#define USERREPO_H

#include "IUserRepo.h"
#include "../File/FileHandle/FileReader.h"
#include "../File/FileHandle/FileWriter.h"
#include "../File/Parser/UserParser.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class UserRepo : public IUserRepo {
private:
    string _filePath;
public:
    UserRepo(const string& filePath);
    vector<UserDAO> getAll() const override;
    bool addUser(const UserDAO& user) override;
    bool updateUser(const UserDAO& user) override;
    bool deleteUser(const string& userId) override;
};

#endif
