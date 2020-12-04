//
// Created by 王泽堃 on 2020-11-25.
//

#ifndef VM_MODEL_H
#define VM_MODEL_H


#include <vector>
#include <memory>
#include "View.h"
#include "Controller.h"
#include "Action.h"

class Model {
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> controller;
    virtual void updateStateImpl(Action &action) = 0;
public:
    virtual ~Model() = default;

    void addView(std::unique_ptr<View> v);

    Action &getAction();

    void updateState(Action &action);

    void updateViews();

    void displayViews();

    void mainLoop();
};


#endif //VM_MODEL_H
