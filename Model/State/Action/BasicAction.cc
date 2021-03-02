//
// Created by 王泽堃 on 2020-11-26.
//

#include "BasicAction.h"

void EmptyAction::operator()(State &s) {
}

void EmptyAction::undo(State &s) {
}

void Concat::operator()(State &s) {
    (*first)(s);
    (*next)(s);
}

void Concat::undo(State &s) {
    next->undo(s);
    first->undo(s);
}

Concat::Concat(std::unique_ptr<Action> first, std::unique_ptr<Action> next) :
        first{std::move(first)}, next{std::move(next)} {}

void MoveCursor::operator()(State &s) {
    s.curRow = toRow;
    s.curCol = toCol;
}

void MoveCursor::undo(State &s) {
}

MoveCursor::MoveCursor(int toRow, int toCol) : toRow(toRow), toCol(toCol) {}

void ChangeMode::operator()(State &s) {
    s.mode = std::move(toMode);
    if (s.buffer.sizeOfLine(s.curRow) != 0) {
        if (s.curCol == s.buffer.sizeOfLine(s.curRow)) {
            s.curCol -= 1;
        }
    }
}

void ChangeMode::undo(State &s) {
}

void Delete::operator()(State &s) {
    deleted = s.buffer.del(row, col, len);
}

void Delete::undo(State &s) {
    s.buffer.add(row, col, deleted);
}

void Add::operator()(State &s) {
    s.buffer.add(row, col, added);
}

void Add::undo(State &s) {
    s.buffer.del(row, col, added.size());
}

Add::Add(int row, int col, const std::string &added) : row(row), col(col), added(added) {}

void NewLine::operator()(State &s) {
    s.buffer.newLine(row);
}

void NewLine::undo(State &s) {
    s.buffer.deleteLine(row);
}

NewLine::NewLine(size_t row) : row{row} {}

DeleteLine::DeleteLine(size_t row) : row{row} {}

void DeleteLine::operator()(State &s) {
    deleted = s.buffer.getLine(row);
    s.buffer.deleteLine(row);
}

void DeleteLine::undo(State &s) {
    //tbd
}

void MoveUp::operator()(State &s) {
    if (s.curRow != 0) {
        size_t prevRow = s.curRow - 1;
        if (s.curCol > s.buffer.sizeOfLine(prevRow)) {
            s.curCol = s.buffer.sizeOfLine(prevRow) - 1;
        }
        s.curRow = prevRow;
    }
}

void MoveUp::undo(State &s) {

}

void MoveRight::operator()(State &s) {
    if (s.curCol != s.buffer.sizeOfLine(s.curRow)) {
        s.curCol += 1;
    }
}

void MoveRight::undo(State &s) {

}

void MoveDown::operator()(State &s) {
    if (s.curRow != s.buffer.size() - 1) {
        size_t nextRow = s.curRow + 1;
        if (s.curCol > s.buffer.sizeOfLine(nextRow)) {
            s.curCol = s.buffer.sizeOfLine(nextRow);
        }
        s.curRow = nextRow;
    }
}

void MoveDown::undo(State &s) {

}

void MoveLeft::operator()(State &s) {
    if (s.curCol != 0) {
        s.curCol -= 1;
    }
}

void MoveLeft::undo(State &s) {

}

void Home::operator()(State &s) {
    s.curCol = 0;
}

void Home::undo(State &s) {

}

void End::operator()(State &s) {
    if (s.buffer.sizeOfLine(s.curRow)) {
        s.curCol = s.buffer.sizeOfLine(s.curRow) - 1;
    }
}

void End::undo(State &s) {

}
