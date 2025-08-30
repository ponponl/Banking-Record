#include "InputView.h"

int InputView::getAccountCreationChoice(MenuView& menu) {
    int selected = 0;
    const int CREATION_SIZE = 3;
    while (true) {
        menu.displayAccountCreationChoice(selected);
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72)
                selected = (selected - 1 + CREATION_SIZE) % CREATION_SIZE;
            else if (key == 80)
                selected = (selected + 1) % CREATION_SIZE;
        } else if (key == 13) {
            if (selected == CREATION_SIZE - 1) return -1; 
            return selected + 1;
        }
    }
}

int InputView::getSearchChoice(MenuView& menu) {
    int selected = 0;
    const int SEARCH_SIZE = 5;
    while (true) {
        menu.displaySearchMenu(selected);
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72)
                selected = (selected - 1 + SEARCH_SIZE) % SEARCH_SIZE;
            else if (key == 80)
                selected = (selected + 1) % SEARCH_SIZE;
        } else if (key == 13) {
            if (selected == SEARCH_SIZE - 1) return -1;
            return selected + 1;
        }
    }
}

int InputView::getUserChoice(MenuView& menu) {
    int selected = 0;
    const int MENU_SIZE = 6; 
    while (true) {
        menu.displayMenu(selected);

        int key = _getch();
        if (key == 224) { 
            key = _getch();
            if (key == 72) 
                selected = (selected - 1 + MENU_SIZE) % MENU_SIZE;
            else if (key == 80) 
                selected = (selected + 1) % MENU_SIZE;
        } else if (key == 13) { 
            return selected + 1;
        }
    }
}
