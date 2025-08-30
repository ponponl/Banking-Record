#ifndef USER_PARSER_H
#define USER_PARSER_H

#include <string>
#include <vector>
#include "../../DAOEntity/UserDAO.h"
using std::string;
using std::vector;

class UserParser {
public:
    static UserDAO parse(const string& line);
    static vector<UserDAO> parseMany(const vector<string>& lines);
    static string serialize(const UserDAO& user);
};

#endif
