//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_BUFFER_H
#define VM_BUFFER_H


#include <cstddef>
#include <string>
#include <iostream>

class Buffer {
public:
    virtual ~Buffer() = default;

    virtual size_t size() = 0;

    virtual void add(size_t row, size_t col, std::string &s) = 0;

    virtual std::string &del(size_t row, size_t col, size_t len) = 0;

    virtual void save(std::ofstream &f) = 0;
};


#endif //VM_BUFFER_H
