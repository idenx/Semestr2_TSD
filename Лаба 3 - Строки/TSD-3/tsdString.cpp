#include "tsdString.h"

int tsdString::length() const {
    return this->size;
}

void tsdString::setLength(int length) {
    this->size = length;
}
