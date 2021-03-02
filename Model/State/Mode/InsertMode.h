//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_INSERTMODE_H
#define VM_INSERTMODE_H


#include "Mode.h"
#include "../Action/InsertModeAction.h"
#include "NormalMode.h"
#include "../Action/BasicAction.h"
#include <ncurses.h>


class InsertMode : public Mode {
public:
    std::unique_ptr<Action> visitController(VmKeyboard &k) override;

    std::string visitView(BarView &b) override;
};


#endif //VM_INSERTMODE_H
