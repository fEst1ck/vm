//
// Created by 王泽堃 on 2020-11-25.
//

#ifndef VM_MODEL_H
#define VM_MODEL_H


#include <vector>
#include <memory>
#include "../View/View.h"
#include "../Controller/Controller.h"
#include "State/Action/Action.h"

class Model {
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> controller;
    virtual void updateStateImpl(std::unique_ptr<Action> action) = 0;
public:
    virtual ~Model() = default;

    void addView(std::unique_ptr<View> v);

    void addController(std::unique_ptr<Controller> kbd);

    std::unique_ptr<Action> getAction();

    void updateState(std::unique_ptr<Action> action);

    void updateViews();

    void displayViews();

    void mainLoop();
};


#endif //VM_MODEL_H
