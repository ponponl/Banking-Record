
#ifndef INPUTVIEW_H
#define INPUTVIEW_H

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include "AccountModel.h"
#include "MenuView.h"

using namespace std;

class InputView {
public:
    int getUserChoice(MenuView& menu);
    int getSearchChoice(MenuView& menu);
};

#endif
