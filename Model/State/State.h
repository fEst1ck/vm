//
// Created by 王泽堃 on 2020-11-26.
//

#ifndef VM_STATE_H
#define VM_STATE_H


#include <vector>
//#include "Action.h"
#include "Buffer/StringBuffer.h"
#include "Mode/Mode.h"
#include "Action/Action.h"
class Mode;
//class Action;
class State {
public:
    ~State() = default;

    explicit State(std::unique_ptr<Mode> startMode);
    std::unique_ptr<Mode> mode;
    size_t curRow = 0;
    size_t curCol = 0; // position of the cursor in the StringBuffer
    StringBuffer buffer;
    std::string fileName;
    std::vector<std::unique_ptr<Action>> history;
};


#endif //VM_STATE_H
