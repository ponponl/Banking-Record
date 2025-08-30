#include "UserService.h"

UserService::UserService(shared_ptr<IUserRepo> repo) : _repo(std::move(repo)) {}

vector<User> UserService::getAllUsers() const {
    vector<UserDAO> daos = _repo->getAll();
    vector<User> users;
    users.reserve(daos.size());
    for (const auto& dao : daos) {
        users.push_back(UserEntityParser::toEntity(dao));
    }
    return users;
}

bool UserService::addUser(const User& user) {
    UserDAO dao = UserEntityParser::toDAO(user);
    return _repo->addUser(dao);
}

bool UserService::deleteUser(const string& userId) {
    return _repo->deleteUser(userId);
}

bool UserService::updateUser(const User& user) {
    UserDAO dao = UserEntityParser::toDAO(user);
    return _repo->updateUser(dao);
}

int UserService::generateNewUserId() const {
    vector<User> users = getAllUsers();
    int maxId = 0;
    for (const auto& user : users) {
        int id = 0;
        try {
            id = user.getId();
        } catch (...) {
            continue;
        }
        if (id > maxId) maxId = id;
    }
    return maxId + 1;
}
