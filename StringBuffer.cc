//
// Created by 王泽堃 on 2020-11-27.
//

#include "StringBuffer.h"
#include <iostream>
#include <fstream>

size_t StringBuffer::size() {
    return theBuffer.size();
}

void StringBuffer::add(size_t row, size_t col, std::string &s) {
    theBuffer[row].insert(col, s);
}

std::string &StringBuffer::del(size_t row, size_t col, size_t len) {
    return theBuffer[row].erase(col, len);
}

void StringBuffer::save(std::ofstream &f) {
    for (auto &l : theBuffer) {
        f << l << std::endl;
    }
}
