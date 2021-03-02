//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_VMKEYBOARD_H
#define VM_VMKEYBOARD_H


#include "Controller.h"
#include "../Model/State/Mode/Mode.h"
#include "../Model/VM.h"

class VmKeyboard : public Controller {
    VM *vm;
    std::unique_ptr<Action> accept(Mode &m);
    std::unique_ptr<Action> action() override;

public:
    explicit VmKeyboard(VM *vm);
};


#endif //VM_VMKEYBOARD_H
