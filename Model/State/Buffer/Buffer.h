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

    virtual size_t sizeOfLine(size_t ln) = 0;

    virtual void add(size_t row, size_t col, std::string &s) = 0;

    virtual char get(size_t row, size_t col) = 0;

    virtual void set(size_t row, size_t col, char c) = 0;

    void appendLine(size_t row, std::string &s);

    virtual std::string &getLine(size_t ln) = 0;

    virtual void newLine(size_t ln) = 0;

    virtual void deleteLine(size_t ln) = 0;

    virtual std::string &del(size_t row, size_t col, size_t len) = 0;

    virtual void save(std::ofstream &f) = 0;
};


#endif //VM_BUFFER_H
