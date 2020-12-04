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

void MoveCursor::operator()(State &s) {
    s.curRow = toRow;
    s.curCol = toCol;
}

void MoveCursor::undo(State &s) {
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
