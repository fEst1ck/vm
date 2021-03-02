//
// Created by 王泽堃 on 2020-11-25.
//

#include "Controller.h"

std::unique_ptr<Action> Controller::getAction() {
    return action();
}

