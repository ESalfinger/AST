//
// Created by Elias Salfinger on 28.11.19.
//
#include <iostream>
#include "headers/Enigma.h"

Enigma::Enigma(int numRotors) : m_numRotors(numRotors), m_reflector(Reflector(ReflectorSeed)) {
    m_rotors = new Rotor *[m_numRotors];
    m_reflector.init();
}

Enigma::~Enigma() {
    delete[] m_rotors;
}

void Enigma::addRotor(RotorType type) {
    int i = 0;
    while (m_rotors[i] != nullptr && i < m_numRotors) {
        i++;
    }

    if (i < m_numRotors) {
        m_rotors[i] = new Rotor(type);
        m_rotors[i]->init();
    }
}

void Enigma::changeRotor(Rotor &rotor, int posIdx) {
    m_rotors[posIdx] = &rotor;
}

void Enigma::setDailyKey(char *key) {
    for (int i = 0; i < m_numRotors; ++i) {
        int turns = toInt(key[i]);
        m_rotors[i]->turn(turns);
    }
}

void Enigma::setMessageKey(char *key) {
    m_msgKey = key;
}

void Enigma::reset() {
    for (int i = 0; i < m_numRotors; ++i) {
        m_rotors[i]->init();
    }
}

std::string Enigma::encrypt(const std::string &msg) {
    std::string s = "";
    for (char c : msg) {
        for (int i = 0; i < m_numRotors; ++i) {
            c = toChar(m_rotors[i]->getCode(toInt(c)));
            m_rotors[i]->turn(1);
        }

        c = m_reflector.getCode(toInt(c));

        for (int i = m_numRotors - 1; i >= 0; --i) {
            c = toChar(m_rotors[i]->getCode(toInt(c)));
            m_rotors[i]->turn(1);
        }
        s += c;
    }
    return s;
}

std::string Enigma::decrypt(const std::string &msg) {
    return std::string();
}

void Enigma::applyMsgKey() {
    for (int i = 0; i < m_numRotors; ++i) {
        int turns = toInt(m_msgKey[i]);
        m_rotors[i]->turn(turns);
    }
}

int Enigma::toInt(char c) {
    int val = c;

    if (val >= 65 && val <= 90) {
        return val - 65;
    } else if (val >= 97 && val <= 122) {
        return val - 97;
    }
}

char Enigma::toChar(int i) {
    return 65 + i;
}

void Enigma::printConfig() {
    for (int i = 0; i < m_numRotors; ++i) {
        std::cout << "-------------Rotor " << i + 1 << "-------------" << std::endl;
        m_rotors[i]->print();
    }
}
