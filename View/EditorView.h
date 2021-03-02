//
// Created by 王泽堃 on 2020-12-09.
//

#ifndef VM_EDITORVIEW_H
#define VM_EDITORVIEW_H


#include "View.h"
#include "../Model/VM.h"
#include <ncurses.h>

class EditorView : public View {
    int startRow = 0; // start row on the screen
    int maxY;
    int maxX;
    VM *vm;
public:
    explicit EditorView(VM *vm);

    ~EditorView() override;

    void update() override;

    void display() override;
};


#endif //VM_EDITORVIEW_H
