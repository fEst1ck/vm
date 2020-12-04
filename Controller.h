//
// Created by 王泽堃 on 2020-11-25.
//

#ifndef VM_CONTROLLER_H
#define VM_CONTROLLER_H


#include "Action.h"

class Controller {
    virtual Action &action() = 0;

public:
    Action &getAction();
};


#endif //VM_CONTROLLER_H
