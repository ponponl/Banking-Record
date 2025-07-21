#pragma once
#include "model.h"

void displayMenu();
int getUserChoice();
void displayAccount(const Account& acc);
void displayAllAccountsHeader();
void displayNotFound();
void displayDeleted(bool success);
void displayUpdated(float newBalance);
