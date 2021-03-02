//
// Created by 王泽堃 on 2020-12-15.
//

#include "NormalModeAction.h"

append::append() {
    theAction = std::make_unique<Concat>(
            std::make_unique<ChangeMode>(std::make_unique<InsertMode>()),
            std::make_unique<MoveRight>());
}

void NormalModeAction::operator()(State &s) {
    (*theAction)(s);
}

void NormalModeAction::undo(State &s) {
    (*theAction).undo(s);
}

Append::Append() {
    theAction = std::make_unique<Concat>(
            std::make_unique<ChangeMode>(std::make_unique<InsertMode>()),
            //std::make_unique<End>()
            std::make_unique<Concat>(
                    std::make_unique<End>(),
                    std::make_unique<MoveRight>()
            )
    );
}

void NormalMoveRight::operator()(State &s) {
    if (s.buffer.sizeOfLine(s.curRow) != 0) {
        if (s.curCol != s.buffer.sizeOfLine(s.curRow) - 1) {
            s.curCol += 1;
        }
    }
}

void NormalMoveRight::undo(State &s) {
}

void NormalMoveUp::operator()(State &s) {
    MoveUp{}(s);
    if (s.curCol == s.buffer.sizeOfLine(s.curRow)) {
        s.curCol -= 1;
    }
    if (s.curCol == -1) {
        s.curCol = 0;
    }
}


void NormalMoveUp::undo(State &s) {
}

void NormalMoveDown::operator()(State &s) {
    MoveDown{}(s);
    if (s.curCol == s.buffer.sizeOfLine(s.curRow)) {
        s.curCol -= 1;
    }
    if (s.curCol == -1) {
        s.curCol = 0;
    }
}

void NormalMoveDown::undo(State &s) {
}

char prevChar(State &s) {
    char prevChar;
    if (s.curCol != 0) {
        prevChar = s.buffer.get(s.curRow, s.curCol - 1);
    } else {
        if (s.curRow == 0) {
            prevChar = 0;
        } else {
            prevChar = '\n';
        }
    }
    return prevChar;
}

void b::operator()(State &s) {
    char prev = prevChar(s);
    if (prev) {
        if (prev == ' ' || prev == '\n' || prev == '\t') {
            if (prev == '\n') {
                s.curRow -= 1;
                if (s.buffer.sizeOfLine(s.curRow) == 0) {
                    s.curCol = 0;
                } else {
                    s.curCol = s.buffer.sizeOfLine(s.curRow) - 1;
                }
            } else {
                s.curCol -= 1;
            }
        }
        prev = prevChar(s);
        while (prev == ' ' || prev == '\t') {
            s.curCol -= 1;
            prev = prevChar(s);
        }
        while (!(prev == 0 || prev == ' ' || prev == '\n' || prev == '\t')) {
            s.curCol -= 1;
            prev = prevChar(s);
        }
    }
}

void b::undo(State &s) {
}

char nextChar(State &s) {
    if (s.buffer.sizeOfLine(s.curRow) == 0) {
        if (s.buffer.size() == 0) {
            return 0;
        } else if (s.buffer.size() - 1 == s.curRow) {
            return 0;
        } else {
            return '\n';
        }
    } else {
        if (s.curCol == s.buffer.sizeOfLine(s.curRow) - 1) {
            if (s.buffer.size() - 1 == s.curRow) {
                return 0;
            } else {
                return '\n';
            }
        } else {
            return s.buffer.get(s.curRow, s.curCol + 1);
        }
    }
}

char curChar(State &s) {
    if (s.buffer.sizeOfLine(s.curRow) == 0) {
        return 0;
    } else {
        return s.buffer.get(s.curRow, s.curCol);
    }
}

void w::operator()(State &s) {
    char nc = nextChar(s);
    if (nc) {
        while (!(nc == '\t' || nc == '\n' || nc == ' ' || nc == 0)) {
            s.curCol += 1;
            nc = nextChar(s);
        }
        if (nc) {
            while (nc == ' ' || nc == '\n' || nc == '\t') {
                if (nc == '\n') {
                    s.curRow += 1;
                    s.curCol = 0;
                } else {
                    s.curCol += 1;
                }
                nc = nextChar(s);
            }
        }
        if (nc) {
            NormalMoveRight{}(s);
        }
    }
}

void w::undo(State &s) {

}

void x::operator()(State &s) {
    if (s.buffer.sizeOfLine(s.curRow)) {
        deleted = curChar(s);
        s.buffer.del(s.curRow, s.curCol, 1);
        if (s.buffer.sizeOfLine(s.curRow) && s.buffer.sizeOfLine(s.curRow) <= s.curCol) {
            MoveLeft{}(s);
        }
    } else {
        deleted = 0;
    }
}

void x::undo(State &s) {
    if (deleted) {
        std::string toAdd{deleted};
        s.buffer.add(s.curRow, s.curCol, toAdd);
    }
}

void o::operator()(State &s) {
    s.buffer.newLine(s.curRow + 1);
    ChangeMode{std::make_unique<InsertMode>()}(s);
    MoveDown{}(s);
}

void o::undo(State &s) {
    s.buffer.deleteLine(s.curRow);
}

void X::operator()(State &s) {
    if (s.buffer.sizeOfLine(s.curRow)) {
        if (s.curCol > 0) {
            deleted = prevChar(s);
            s.buffer.del(s.curRow, s.curCol - 1, 1);
        }
        MoveLeft{}(s);
    } else {
        deleted = 0;
    }
}

void X::undo(State &s) {
    if (deleted) {
        std::string toAdd{deleted};
        s.buffer.add(s.curRow, s.curCol, toAdd);
    }
}

void O::operator()(State &s) {
    row = s.curRow;
    s.buffer.newLine(s.curRow);
    ChangeMode{std::make_unique<InsertMode>()}(s);
    s.curCol = 0;
}

void O::undo(State &s) {
    s.buffer.deleteLine(row);
}

void zero::operator()(State &s) {
    Home{}(s);
}

void zero::undo(State &s) {
}

void dollar::operator()(State &s) {
    End{}(s);
}

void dollar::undo(State &s) {
}

void r::operator()(State &s) {
    row = s.curRow;
    col = s.curCol;
    if (s.buffer.sizeOfLine(s.curRow)) {
        changed = s.buffer.get(s.curRow, s.curCol);
        s.buffer.set(s.curRow, s.curCol, to);
    } else {
        changed = 0;
    }
}

void r::undo(State &s) {
    if (changed) {
        s.buffer.set(row, col, changed);
    }
}

r::r(char to) : to(to) {}

R::R(char to) : to(to) {}

void R::operator()(State &s) {

}

void R::undo(State &s) {
}

void cc::operator()(State &s) {
    row = s.curRow;
    deleted = s.buffer.getLine(s.curRow);
    std::string str{""};
    s.buffer.setLine(s.curRow, str);
    Home{}(s);
    ChangeMode{std::make_unique<InsertMode>()}(s);
}

void cc::undo(State &s) {
    s.buffer.setLine(row, deleted);
}

Normals::Normals() {
    theAction = std::make_unique<Concat>(
            std::make_unique<x>(),
            std::make_unique<ChangeMode>(std::make_unique<InsertMode>())
    );
}


void dd::operator()(State &s) {
    row = s.curRow;
    deleted = s.buffer.getLine(row);
    s.buffer.deleteLine(row);
    s.curCol = 0;
    if (s.buffer.size() > 1 && s.buffer.size() == row) {
        s.curRow -= 1;
    }
}

void dd::undo(State &s) {
    s.buffer.add(row, 0, deleted);
}

void save::operator()(State &s) {
    std::ofstream f {s.fileName};
    s.buffer.save(f);
}

void save::undo(State &s) {

}
