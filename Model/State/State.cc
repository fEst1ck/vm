//
// Created by 王泽堃 on 2020-11-26.
//

#include "State.h"

State::State(std::unique_ptr<Mode> startMode) : mode {std::move(startMode)} {

}
