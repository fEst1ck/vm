//
// Created by 王泽堃 on 2020-11-26.
//

#ifndef VM_BASICACTION_H
#define VM_BASICACTION_H


#include <string>
#include "Action.h"

class BasicAction : public Action {
};

class EmptyAction : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class Concat : public BasicAction {
    std::unique_ptr<Action> first;
    std::unique_ptr<Action> next;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class MoveCursor : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;

    int toRow;
    int toCol;
};

class Delete : public BasicAction {
    std::string deleted;
public:
    void operator()(State &s) override;

    void undo(State &s) override;

private:
    int row;
    int col;
    int len;
};

class Add : public BasicAction {
    int row;
    int col;
    std::string added;
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

#endif //VM_BASICACTION_H
