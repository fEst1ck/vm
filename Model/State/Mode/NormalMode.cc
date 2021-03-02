//
// Created by 王泽堃 on 2020-12-07.
//

#include "NormalMode.h"


std::unique_ptr<Action> NormalMode::visitController(VmKeyboard &k) {
    int ch = getch();
    if (s == nothing) {
       if (ch == 'a') {
            return std::make_unique<append>();
        } else if (ch == 'A') {
            return std::make_unique<Append>();
        } else if (ch == 'h') {
            return std::make_unique<MoveLeft>();
        } else if (ch == 'j') {
            return std::make_unique<NormalMoveDown>();
        } else if (ch == 'k') {
            return std::make_unique<NormalMoveUp>();
        } else if (ch == 'l') {
            return std::make_unique<NormalMoveRight>();
        } else if (ch == 'i') {
            return std::make_unique<ChangeMode>(std::make_unique<InsertMode>());
        } else if (ch == 'b') {
            return std::make_unique<b>();
        } else if (ch == 'w') {
            return std::make_unique<w>();
        } else if (ch == 'x') {
            return std::make_unique<x>();
        } else if (ch == 'o') {
            return std::make_unique<o>();
        } else if (ch == 'X') {
            return std::make_unique<X>();
        } else if (ch == 'O') {
            return std::make_unique<O>();
        } else if (ch == '0') {
            return std::make_unique<zero>();
        } else if (ch == '$') {
            return std::make_unique<dollar>();
        } else if (ch == 's') {
            return std::make_unique<Normals>();
        } else if (ch == 'S') {
            return std::make_unique<cc>();
        } else if (ch == 'r') {
            s = rx;
            return std::make_unique<EmptyAction>();
        } else if (ch == 'R') {
            s = Rx;
            return std::make_unique<EmptyAction>();
        } else if (ch == 'c') {
            s = cx;
            return std::make_unique<EmptyAction>();
        } else if (ch == 'd') {
            s = dx;
            return std::unique_ptr<EmptyAction>{new EmptyAction{}};
        } else if (ch == ':') {
            s = colx;
           return std::unique_ptr<EmptyAction>{new EmptyAction{}};
        }
        else {
            return std::unique_ptr<EmptyAction>{new EmptyAction{}};
        }
    } else if (s == dx) {
        if (ch == 'd') {
            s = nothing;
            return std::make_unique<dd>();
        } else {
            s = nothing;
            return std::unique_ptr<EmptyAction>{new EmptyAction{}};
        }
    } else if (s == colx) {
        if (ch == 'q') {
            throw ExitVM {};
        } else if (ch == 'w') {
            s = nothing;
            return std::make_unique<save>();
        } else {
            s = nothing;
            return std::unique_ptr<EmptyAction>{new EmptyAction{}};
        }
    } else if (s == rx) {
        if (32 <= ch && ch <= 126) {
            s = nothing;
            return std::make_unique<r>(ch);
        } else {
            s = nothing;
            return std::make_unique<EmptyAction>();
        }
    } else if (s == Rx) {
        s = nothing;
        return std::make_unique<EmptyAction>();
    } else if (s == cx) {
        if (ch == 'c') {
            s = nothing;
            return std::make_unique<cc>();
        } else {
            s = nothing;
            return std::make_unique<EmptyAction>();
        }
    } else {
        s = nothing;
        return std::unique_ptr<EmptyAction>{new EmptyAction{}};
        // s == yx
    }
}

std::string NormalMode::visitView(BarView &b) {
    std::string s{"Normal Mode"};
    return s;
}
