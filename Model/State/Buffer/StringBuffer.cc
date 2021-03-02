//
// Created by 王泽堃 on 2020-11-27.
//

#include "StringBuffer.h"
#include <fstream>

size_t StringBuffer::size() {
    return theBuffer.size();
}

// insert string at position (row, col)
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

void StringBuffer::newLine(size_t ln) {
    auto itPos = theBuffer.begin() + ln;
    theBuffer.insert(itPos, "");
}

void StringBuffer::deleteLine(size_t ln) {
    auto itPos = theBuffer.begin() + ln;
    theBuffer.erase(itPos);
    if (theBuffer.empty()) {
        theBuffer.insert(theBuffer.begin(), "");
    }
}

size_t StringBuffer::sizeOfLine(size_t ln) {
    return theBuffer[ln].size();
}

std::string &StringBuffer::getLine(size_t ln) {
    return theBuffer[ln];
}

char StringBuffer::get(size_t row, size_t col) {
    return theBuffer[row][col];
}

void StringBuffer::set(size_t row, size_t col, char c) {
    theBuffer[row][col] = c;
}

void StringBuffer::setLine(size_t row, std::string &s) {
    theBuffer[row] = s;
}

void StringBuffer::read(std::ifstream &f) {
    std::string curLn;
    theBuffer.erase(theBuffer.begin());
    while (std::getline(f, curLn)) {
        theBuffer.push_back(curLn);
    }
    if (theBuffer.empty()) {
        theBuffer = {""};
    }
}
