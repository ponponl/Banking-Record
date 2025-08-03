#include "BalanceFormatter.h"
#include <sstream>
#include <iomanip>
#include <locale>
#include <algorithm>

class CommaSeparator : public std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ','; }
    std::string do_grouping() const override { return "\3"; } 
};

std::string BalanceFormatter::formatCurrency(double value, int precision) {
    std::stringstream ss;
    ss.imbue(std::locale(std::locale::classic(), new CommaSeparator));
    ss << std::fixed << std::setprecision(precision) << value;
    return ss.str();
}

double BalanceFormatter::parseFormattedNumber(const std::string& str) {
    std::string cleaned;
    for (char ch : str) {
        if (std::isdigit(ch) || ch == '.' || ch == '-') {
            cleaned += ch;
        }
    }
    return std::stod(cleaned);
}
