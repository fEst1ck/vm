//
// Created by 王泽堃 on 2020-11-27.
//

#include "InsertMode.h"


const int ESCAPE = 27;
const int ENTER = 10;

std::unique_ptr<Action> InsertMode::visitController(VmKeyboard &k) {
    int ch = getch();
    if (ch == ESCAPE) {
        return std::unique_ptr<ChangeMode>{new ChangeMode{std::unique_ptr<Mode>{new NormalMode{}}}};
    } else if (ch == ENTER) {
        return std::make_unique<InsertNewLine>();
    } else if (ch == '\t') {
        return std::make_unique<Tab>();
    } else if (ch == KEY_BACKSPACE) {
        return std::make_unique<BackSpace>();
    } else if (ch == KEY_UP) {
        return std::make_unique<MoveUp>();
    } else if (ch == KEY_RIGHT) {
        return std::make_unique<MoveRight>();
    } else if (ch == KEY_LEFT) {
        return std::make_unique<MoveLeft>();
    } else if (ch == KEY_DOWN) {
        return std::make_unique<MoveDown>();
    } else {
        return std::unique_ptr<InsertChar>{new InsertChar{ch}};
    }
}

std::string InsertMode::visitView(BarView &b) {
    std::string s {"Insert Mode"};
    return s;
}
