//
// Created by 王泽堃 on 2020-11-27.
//

#include "VM.h"

void VM::updateStateImpl(Action &action) {
    action(state);
}
