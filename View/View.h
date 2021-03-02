//
// Created by 王泽堃 on 2020-11-25.
//

#ifndef VM_VIEW_H
#define VM_VIEW_H


class View {
public:
    virtual ~View() = default;
    virtual void update() = 0;
    virtual void display() = 0;
};


#endif //VM_VIEW_H
