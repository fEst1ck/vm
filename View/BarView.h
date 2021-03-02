//
// Created by 王泽堃 on 2020-12-15.
//

#ifndef VM_BARVIEW_H
#define VM_BARVIEW_H


#include "View.h"
#include "../Model/VM.h"
#include <ncurses.h>


class BarView : public View {
    int maxY;
    int maxX;
    VM *vm;
public:
    explicit BarView(VM *vm);

    void update() override;

    void display() override;
};


#endif //VM_BARVIEW_H
