//
// Created by 王泽堃 on 2020-11-26.
//

#ifndef VM_BASICACTION_H
#define VM_BASICACTION_H


#include <string>
#include "Action.h"
#include "../State.h"

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
    Concat(std::unique_ptr<Action> first, std::unique_ptr<Action> next);

    void operator()(State &s) override;

    void undo(State &s) override;
};

class ChangeMode : public BasicAction {
    std::unique_ptr<Mode> toMode;
public:
    explicit ChangeMode(std::unique_ptr<Mode> toMode): toMode{std::move(toMode)} {}
    void operator()(State &s) override;

    void undo(State &s) override;
};

class MoveCursor : public BasicAction {
public:
    MoveCursor(int toRow, int toCol);

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
    Add(int row, int col, const std::string &added);

    void operator()(State &s) override;

    void undo(State &s) override;
};

class NewLine : public BasicAction {
    size_t row; // add new line after this row
public:
    explicit NewLine(size_t row);

    void operator()(State &s) override;

    void undo(State &s) override;
};

class DeleteLine : public BasicAction {
    size_t row;
    std::string deleted;
public:
    DeleteLine(size_t row);

    void operator()(State &s) override;

    void undo(State &s) override;
};

class MoveUp : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class MoveRight : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class MoveDown : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class MoveLeft : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class Home : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

class End : public BasicAction {
public:
    void operator()(State &s) override;

    void undo(State &s) override;
};

#endif //VM_BASICACTION_H
