//
// Created by 王泽堃 on 2020-11-25.
//

#ifndef VM_CONTROLLER_H
#define VM_CONTROLLER_H


#include "../Model/State/Action/Action.h"
#include <memory>

class Controller {
    virtual std::unique_ptr<Action> action() = 0;
public:
    virtual ~Controller() = default;

    std::unique_ptr<Action> getAction();
};


#endif //VM_CONTROLLER_H
