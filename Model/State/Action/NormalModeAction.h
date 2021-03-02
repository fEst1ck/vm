//
// Created by 王泽堃 on 2020-12-15.
//

#ifndef VM_NORMALMODEACTION_H
#define VM_NORMALMODEACTION_H


#include "Action.h"
#include "BasicAction.h"
#include "InsertModeAction.h"
#include "../Mode/InsertMode.h"
#include "fstream"

class NormalModeAction : public Action {
public:
    std::unique_ptr<Action> theAction;
    virtual void operator()(State &s) override;
    virtual void undo(State &s) override;
};

class append : public NormalModeAction {
public:
    append();
};

class Append : public NormalModeAction {
public:
    Append();
};

class NormalMoveRight : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class NormalMoveUp : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class NormalMoveDown : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class b : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class w : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class x : public NormalModeAction {
    char deleted;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class X : public NormalModeAction {
    char deleted;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class o : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class O : public NormalModeAction {
    size_t row;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class zero : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class dollar : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class r : public NormalModeAction {
    char changed;
    char to;
    size_t row;
    size_t col;
public:
    r(char to);

public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class R : public NormalModeAction {
    char changed;
    char to;
public:
    R(char to);

    void operator()(State &s) override;

    void undo(State &s) override;
};

class cc : public NormalModeAction {
    std::string deleted;
    size_t row;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class Normals : public NormalModeAction {
public:
    Normals();
};

class dd : public NormalModeAction {
    std::string deleted;
    size_t row;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class save : public NormalModeAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};


#endif //VM_NORMALMODEACTION_H
