//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_VM_H
#define VM_VM_H


#include "Mode.h"
#include "State.h"
#include "Model.h"

class VM : public Model {
    void updateStateImpl(Action &action) override;
    State state;
};


#endif //VM_VM_H
