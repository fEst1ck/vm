//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_STRINGBUFFER_H
#define VM_STRINGBUFFER_H


#include <string>
#include <vector>
#include "Buffer.h"
#include <iostream>

class StringBuffer : public Buffer {
    std::vector<std::string> theBuffer = {""};
public:
    ~StringBuffer() override = default;
    //~StringBuffer() override {}

    size_t size() override;

    size_t sizeOfLine(size_t ln) override;

    void add(size_t row, size_t col, std::string &s) override;

    char get(size_t row, size_t col) override;

    void set(size_t row, size_t col, char c) override;

    void setLine(size_t row, std::string &s);

    std::string &del(size_t row, size_t col, size_t len) override;

    void read(std::ifstream &f);

    void save(std::ofstream &f) override;

    void newLine(size_t ln) override;

    std::string &getLine(size_t ln) override;

    void deleteLine(size_t ln) override;
};


#endif //VM_STRINGBUFFER_H
