//
// Created by 王泽堃 on 2020-11-27.
//

#ifndef VM_STRINGBUFFER_H
#define VM_STRINGBUFFER_H


#include <string>
#include <vector>
#include "StringBuffer.h"

class StringBuffer : public StringBuffer {
    std::vector<std::string> theBuffer;
public:
    size_t size() override;

    void add(size_t row, size_t col, std::string &s) override;

    std::string &del(size_t row, size_t col, size_t len) override;

    void save(std::ofstream &f) override;
};


#endif //VM_STRINGBUFFER_H
