//
// Created by 王泽堃 on 2020-11-25.
//

#include "Model.h"

void Model::addView(std::unique_ptr<View> v) {
    views.push_back(std::move(v));
}

std::unique_ptr<Action> Model::getAction() {
    return controller->getAction();
}

void Model::updateState(std::unique_ptr<Action> action) {
    updateStateImpl(std::move(action));
}

void Model::updateViews() {
    for (auto &v : views) {
        v->update();
    }
}

void Model::displayViews() {
    for (auto &v : views) {
        v->display();
    }
}

void Model::mainLoop() {
    displayViews();
    while (1) {
        try {
            updateState(getAction());
            updateViews();
            displayViews();
        } catch (...) {
            break;
        }
    }
}

void Model::addController(std::unique_ptr<Controller> kbd) {
    controller = std::move(kbd);
}
