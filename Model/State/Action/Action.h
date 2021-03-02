//
// Created by 王泽堃 on 2020-11-25.
//

#ifndef VM_ACTION_H
#define VM_ACTION_H


//#include "State.h"
class State;

class Action {
public:
    virtual ~Action() = default;
    virtual void operator()(State &s) = 0;
    virtual void undo(State &s) = 0;
};

#endif //VM_ACTION_H
