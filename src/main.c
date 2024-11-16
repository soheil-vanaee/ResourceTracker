#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "getinfo.h"

int main() {

    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    WINDOW *win = newwin(20, 50, 1, 1);
    box(win, 0, 0);

    while (1) {
        werase(win);
        box(win, 0, 0);

        memory_info(win);
        cpu_info(win);
        disk_info(win);

        wrefresh(win);
    }

    delwin(win);
    endwin();
    return 0;
}
