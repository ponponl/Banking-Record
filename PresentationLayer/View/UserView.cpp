#include "UserView.h"
#include <iostream>
using std::cout; using std::cin; using std::getline;

int UserView::inputUserId() {
	int userId = 0;
	std::cout << "Enter user ID: ";
	while (!(std::cin >> userId)) {
		std::cin.clear(); std::cin.ignore(10000, '\n');
		std::cout << "Invalid user ID. Please try again: ";
	}
	std::cin.ignore(10000, '\n');
	return userId;
}

void UserView::inputUser(UserModel& user) {
	string name, phone;
	cout << "Enter user name: ";
	while (true) {
		getline(cin, name);
		auto result = InputValidation::validateName(name);
		if (!result) {
			cout << result.error() << " Please try again!\n";
			continue;
		}
		break;
	}
	cout << "Enter phone number: ";
	while (true) {
		getline(cin, phone);
		auto result = InputValidation::validatePhone(phone);
		if (!result) {
			cout << result.error() << " Please try again!\n";
			continue;
		}
		break;
	}
	user.setName(name);
	user.setPhoneNumber(phone);
}

bool UserView::updateUserInfo(string& newName, bool& updateName, string& newPhone, bool& updatePhone) {
	updateName = updatePhone = false;
	char choice;
	do {
		cout << "Do you want to update the user name? (y/n): ";
		cin >> choice;
		cin.ignore(10000, '\n');
		if (!InputValidation::isValidYesNo(choice)) {
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
		}
	} while (!InputValidation::isValidYesNo(choice));
	if (choice == 'y' || choice == 'Y') {
		while (true) {
			cout << "Enter new name: ";
			getline(cin, newName);
			auto result = InputValidation::validateName(newName);
			if (!result) {
				cout << result.error() << " Please try again!\n";
				continue;
			}
			updateName = true;
			break;
		}
	}
	do {
		cout << "Do you want to update the phone number? (y/n): ";
		cin >> choice;
		cin.ignore(10000, '\n');
		if (!InputValidation::isValidYesNo(choice)) {
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
		}
	} while (!InputValidation::isValidYesNo(choice));
	if (choice == 'y' || choice == 'Y') {
		while (true) {
			cout << "Enter new phone number: ";
			getline(cin, newPhone);
			auto result = InputValidation::validatePhone(newPhone);
			if (!result) {
				cout << result.error() << " Please try again!\n";
				continue;
			}
			updatePhone = true;
			break;
		}
	}
	return updateName || updatePhone;
}
