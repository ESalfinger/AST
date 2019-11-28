//
// Created by Elias Salfinger on 20.11.19.
//
#include "headers/PointerKey.h"

PointerKey::PointerKey(void *pointer) : pointer(pointer) {}

PointerKey::~PointerKey() {

}

bool PointerKey::matches(void *data) {
    return pointer == data;
}
