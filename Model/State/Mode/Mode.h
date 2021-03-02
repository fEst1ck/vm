//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_MODE_H
#define VM_MODE_H

#include <memory>
class Action;
class VmKeyboard;
//#include "BarView.h"
class BarView;
class Mode {
public:
    virtual ~Mode() = default;
    virtual std::unique_ptr<Action> visitController(VmKeyboard &k) = 0;
    virtual std::string visitView(BarView &b) = 0;
};


#endif //VM_MODE_H
