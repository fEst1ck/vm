//
// Created by 王泽堃 on 2020-11-27.
//

#include "VmKeyboard.h"
#include <iostream>

std::unique_ptr<Action> VmKeyboard::action() {
    return accept(*(vm->state.mode));
}

std::unique_ptr<Action> VmKeyboard::accept(Mode &m) {
    return m.visitController(*this);
}

VmKeyboard::VmKeyboard(VM *vm) : vm{vm} {}
