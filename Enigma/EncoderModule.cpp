//
// Created by Elias Salfinger on 28.11.19.
//
#include <iostream>
#include <cstdlib>
#include "headers/EncoderModule.h"

EncoderModule::EncoderModule(int randSeed) {
    srand(randSeed);
}

EncoderModule::~EncoderModule() {
}

void EncoderModule::print() const {
    for (int i = 0; i < NUM_LETTERS; ++i) {
        std::cout << static_cast<char>(97 + i) << ": " << static_cast<char>(97 + m_configuration[i]) << std::endl;
    }
}

int EncoderModule::getCode(int idx) const {
    return m_configuration[idx];
}

int EncoderModule::getIndex(int element) const {
    for (int i = 0; i < NUM_LETTERS; ++i) {
        if (m_configuration[i] == element) {
            return i;
        }
    }
    return 0;
}
