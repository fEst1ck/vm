//
// Created by 王泽堃 on 2020-11-26.
//

#ifndef VM_STATE_H
#define VM_STATE_H


#include <vector>
#include "Action.h"
#include "StringBuffer.h"
#include "Mode.h"

class State {
public:
    std::unique_ptr<Mode> mode;
    int curRow;
    int curCol; // position of the cursor in the StringBuffer
    int startRow; // start row on the screen
    StringBuffer buffer;
    std::vector<Action> history;
};


#endif //VM_STATE_H
