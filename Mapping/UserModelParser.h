#ifndef USER_MODEL_PARSER_H
#define USER_MODEL_PARSER_H

#include "../PresentationLayer/InputModel/UserModel.h"
#include "../BusinessLayer/BusinessEntity/User.h"

class UserModelParser {
    public:
        static User toEntity(const UserModel& model) {
            return User(model.getUserId(), model.getName(), model.getPhoneNumber());
        }

        static UserModel toModel(const User& entity) {
            return UserModel(entity.getId(), entity.getName(), entity.getPhoneNumber());
        }
};

#endif
