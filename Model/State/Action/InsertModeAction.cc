//
// Created by 王泽堃 on 2020-12-08.
//

#include "InsertModeAction.h"



void InsertNewLine::operator()(State &s) {
    NewLine{s.curRow + 1}(s);
    std::string moved = s.buffer.getLine(s.curRow).substr(s.curCol);
    s.buffer.del(s.curRow, s.curCol, moved.size());
    s.curRow += 1;
    s.curCol = 0;
    s.buffer.add(s.curRow, s.curCol, moved);
}

void InsertNewLine::undo(State &s) {
    NewLine{s.curRow}.undo(s);
}

void InsertChar::operator()(State &s) {
    row = s.curRow;
    col = s.curCol;
    std::string toAdd {static_cast<char>(ch)};
    s.buffer.add(s.curRow, s.curCol, toAdd);
    s.curCol += 1;
}

void InsertChar::undo(State &s) {
    s.buffer.del(row, col, 1);
}

InsertChar::InsertChar(int ch) : ch(ch) {}

void BackSpace::operator()(State &s) {
    col = s.curCol;
    row = s.curRow;
    if (s.curCol == 0) {
        if (s.curRow != 0) {
            size_t prev_row = s.curRow - 1;
            prevRowSize = s.buffer.sizeOfLine(prev_row);
            s.buffer.appendLine(prev_row, s.buffer.getLine(s.curRow));
            s.buffer.deleteLine(s.curRow);
            s.curRow = prev_row;
            s.curCol = prevRowSize;
            deleted = '\n';
        } else {
            deleted = 0;
        }
    } else {
        deleted = s.buffer.del(s.curRow, s.curCol - 1, 1)[0];
        s.curCol -= 1;
    }
}

void BackSpace::undo(State &s) {
    if (deleted) {
        if (deleted == '\n') {
            if (col != 0) {
                std::string deletedLn = s.buffer.getLine(s.curRow).substr(prevRowSize);
                s.buffer.newLine(s.curRow + 1);
                s.buffer.add(s.curRow + 1, 0, deletedLn);
            }
        } else {
            std::string toAdd {static_cast<char>(deleted)};
            s.buffer.add(row, col, toAdd);
        }
    }
}

void Tab::operator()(State &s) {
    std::string toAdd {"    "};
    s.buffer.add(s.curRow, s.curCol, toAdd);
    s.curCol += 4;
}

void Tab::undo(State &s) {
    s.buffer.del(s.curRow, s.curCol - 4, 4);
}
