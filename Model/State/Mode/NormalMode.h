//
// Created by 王泽堃 on 2020-12-07.
//

#ifndef VM_NORMALMODE_H
#define VM_NORMALMODE_H


#include "Mode.h"
#include "../Action/InsertModeAction.h"
#include "../Action/BasicAction.h"
#include "../Action/NormalModeAction.h"

class ExitVM {};
class NormalMode : public Mode {
    enum status {
        nothing,
        cx,
        dx,
        yx,
        colx,
        rx,
        Rx,
    };
    status s = nothing;
public:
    std::unique_ptr<Action> visitController(VmKeyboard &k) override;

    std::string visitView(BarView &b) override;
};


#endif //VM_NORMALMODE_H
