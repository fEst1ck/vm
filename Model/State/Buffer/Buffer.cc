#include "Buffer.h"

void Buffer::appendLine(size_t row, std::string &s) {
    add(row, sizeOfLine(row), s);
}
