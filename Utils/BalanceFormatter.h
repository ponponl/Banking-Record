#ifndef BALANCE_FORMATTER_H
#define BALANCE_FORMATTER_H

#include <string>
using std::string;
class BalanceFormatter {
public:
    static string formatCurrency(double value, int precision = 2);

    static double parseFormattedNumber(const string& str);
};

#endif
