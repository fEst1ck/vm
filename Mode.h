//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_MODE_H
#define VM_MODE_H


#include "Action.h"

class Mode {
public:
    virtual Action &action();
};


#endif //VM_MODE_H
