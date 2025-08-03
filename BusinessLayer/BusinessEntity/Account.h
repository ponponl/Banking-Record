#pragma once
#include <string>
#include <iostream>

class Account {
private:
    int accountNumber;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    float balance;

public:
    // Constructor
    Account(int accNo, const std::string& fName, const std::string& lName, const std::string& phone, float bal);

    // Default constructor
    Account();

    // Getters
    int getAccountNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    float getBalance() const;
    std::string getPhoneNumber() const;

    // Setters
    void setAccountNumber(int id);  
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setBalance(float bal);
    void setPhoneNumber(const std::string& phone);

    // Display (for console)
    void display() const;
};
