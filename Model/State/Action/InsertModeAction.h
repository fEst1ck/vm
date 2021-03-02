//
// Created by 王泽堃 on 2020-12-08.
//

#ifndef VM_INSERTMODEACTION_H
#define VM_INSERTMODEACTION_H


#include "Action.h"
#include "BasicAction.h"
#include "../State.h"

class InsertModeAction : public Action {
};

class InsertNewLine : public InsertModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class InsertChar : public InsertModeAction {
    int ch;
    size_t row;
    size_t col;
public:
    InsertChar(int ch);

    void operator()(State &s) override;

    void undo(State &s) override;
};

class BackSpace : public InsertModeAction {
    int deleted;
    size_t prevRowSize;
    size_t row;
    size_t col;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class Tab : public InsertModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};


#endif //VM_INSERTMODEACTION_H
