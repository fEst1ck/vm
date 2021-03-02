//
// Created by 王泽堃 on 2020-12-15.
//

#include "BarView.h"

void BarView::update() {
    State &sta = vm->state;
    std::string s = sta.mode->visitView(*this);
    int prevY;
    int prevX;
    getyx(stdscr, prevY, prevX);
    move(maxY - 1, 0);
    addstr(s.c_str());
    move(maxY - 1, maxX - 8);
    printw("(%d, %d)", sta.curRow, sta.curCol);
    move(prevY, prevX);
    refresh();
}

void BarView::display() {

}

BarView::BarView(VM *vm) : vm{vm} {
    getmaxyx(stdscr, maxY, maxX);
}
