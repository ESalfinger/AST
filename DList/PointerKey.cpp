#include "headers/PointerKey.h"

PointerKey::PointerKey(void *pointer) : pointer(pointer) {}

PointerKey::~PointerKey() {
}

bool PointerKey::matches(void *data) {
    return pointer == data;
}
