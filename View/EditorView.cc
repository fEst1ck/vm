//
// Created by 王泽堃 on 2020-12-09.
//

#include "EditorView.h"

void EditorView::update() {
    clear();
    State &state = vm->state;
    if (state.curRow >= startRow + maxY) {
        startRow += state.curRow + 1 - (startRow + maxY);
    }
    if (state.curRow < startRow) {
        startRow -= startRow - state.curRow;
    }
    for (size_t i = startRow; i < startRow + maxY && i < startRow + state.buffer.size(); ++i) {
        printw(state.buffer.getLine(i).c_str());
        printw("\n");
    }
//    for (size_t i = 0; i < state.buffer.size(); ++i) {
//        printw(state.buffer.getLine(i).c_str());
//        printw("\n");
//    }
    move(state.curRow - startRow, state.curCol);
    //move(state.curRow, state.curCol);
}

void EditorView::display() {
    refresh();
}

EditorView::EditorView(VM *vm) : vm{vm} {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, maxY, maxX);
    maxY = maxY - 1;
}

EditorView::~EditorView() {
    clear();
    endwin();
}
