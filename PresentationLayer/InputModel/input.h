#pragma once
#include <string>

class Account {
private:
    int accNo;
    std::string name;
    std::string type;
    float balance;
public:
    // Constructor mặc định
    Account();

    // Constructor đầy đủ
    Account(int accNo, const std::string& name, const std::string& type, float balance);

    // Getter
    int getAccountNumber() const;
    std::string getName() const;
    std::string getType() const;
    float getBalance() const;

    // Setter
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setBalance(float balance);
    //rut tien
    bool withdraw(float amount);

};
