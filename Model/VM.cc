//
// Created by 王泽堃 on 2020-11-27.
//

#include "VM.h"
#include "fstream"

inline bool fileExists (std::string &fn) {
    std::ifstream f{fn.c_str()};
    return f.good();
}

void VM::updateStateImpl(std::unique_ptr<Action> action) {
    action->operator()(state);
}

VM::VM() : state{std::make_unique<InsertMode>()} {
}

void VM::setBuffer(std::string &s) {
    state.fileName = s;
    if (fileExists(s)) {
        std::ifstream f {s};
        state.buffer.read(f);
    }
}
