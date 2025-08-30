#ifndef USER_ENTITY_PARSER
#define USER_ENTITY_PARSER

#include "../BusinessLayer/BusinessEntity/User.h"
#include "../DataAccessLayer/DAOEntity/UserDAO.h"
#include <string>

class UserEntityParser {
	public:
		static User toEntity(const UserDAO& dao) {
			int id = 0;
			try {
				id = std::stoi(dao.getId());
			} catch (...) {
				id = 0;
			}
			return User(id, dao.getName(), dao.getPhoneNumber());
		}

		static UserDAO toDAO(const User& user) {
			return UserDAO(std::to_string(user.getId()), user.getName(), user.getPhoneNumber());
		}
};

#endif
