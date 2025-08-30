#ifndef PHONE_FORMATTER_H
#define PHONE_FORMATTER_H

#include <string>
using std::string;

class PhoneFormatter {
public:
    static string format(const string& phone) {
        if (phone.length() == 10) {
            return phone.substr(0, 3) + " " + phone.substr(3, 3) + " " + phone.substr(6, 4);
        }
        return phone;
    }
};

#endif
