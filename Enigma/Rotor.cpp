//
// Created by Elias Salfinger on 28.11.19.
//
#include <cstdlib>
#include "headers/Rotor.h"

Rotor::~Rotor() {
}

void Rotor::init() {
    int visited[NUM_LETTERS] = {};
    int count = 0;
    while (count < NUM_LETTERS) {
        int num = rand() % NUM_LETTERS;

        // check if num has already been generated
        if (visited[num] == 0) {
            // now mark it as visited
            visited[num] = 1;
            m_configuration[count++] = num;  // store the generated number in an array.
        }
    }
}

void Rotor::turn(int times) {
    for (int j = 0; j < times; ++j) {
        int dummy = m_configuration[NUM_LETTERS - 1];

        for (int i = NUM_LETTERS - 1; i >= 0; --i) {
            m_configuration[i] = m_configuration[i - 1];
        }

        m_configuration[0] = dummy;
    }
}
