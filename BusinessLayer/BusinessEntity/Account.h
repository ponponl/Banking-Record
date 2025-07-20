#pragma once
#include <string>
#include <iostream>

class Account {
private:
    int accountNumber;
    std::string firstName;
    std::string lastName;
    double balance;

public:
    // Constructor
    Account(int accNo, const std::string& fName, const std::string& lName, double bal);

    // Default constructor
    Account();

    // Getters
    int getAccountNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    double getBalance() const;

    // Setters
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setBalance(double bal);

    // Display (for console)
    void display() const;
};
