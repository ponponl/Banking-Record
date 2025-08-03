#pragma once
#include <string>

class BalanceFormatter {
public:
    static std::string formatCurrency(double value, int precision = 2);

    static double parseFormattedNumber(const std::string& str);
};
