//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_VM_H
#define VM_VM_H


//#include "Mode.h"
#include "State/Mode/InsertMode.h"
#include "State/State.h"
#include "Model.h"

class VM : public Model {
public:
    ~VM() override = default;
    VM();
    void setBuffer(std::string &s);

private:
    void updateStateImpl(std::unique_ptr<Action> action) override;
    State state;
    friend class VmKeyboard;
    friend class EditorView;
    friend class BarView;
};


#endif //VM_VM_H
