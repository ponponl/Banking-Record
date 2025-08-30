#ifndef USERVIEW_H
#define USERVIEW_H

#include "../InputModel/UserModel.h"
#include "../Validation/InputValidation.h"
#include <string>
using std::string;

class UserView {
	public:
		void inputUser(UserModel& user);
		bool updateUserInfo(string& newName, bool& updateName, string& newPhone, bool& updatePhone);
		int inputUserId();
};

#endif
