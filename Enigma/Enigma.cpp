#include <iostream>
#include "headers/Enigma.h"

int Enigma::rotorCount = 0;

Enigma::Enigma(int numRotors) : m_numRotors(numRotors), m_reflector(Reflector(ReflectorSeed)) {
    m_rotors = new Rotor *[numRotors];
    m_turns[numRotors] = {};
    m_reflector.init();
    m_dailyKey = nullptr;
}

Enigma::~Enigma() {
    delete[] m_rotors;
}

void Enigma::addRotor(RotorType type) {
    if (rotorCount < m_numRotors) {
        m_rotors[rotorCount] = new Rotor(type);
        m_rotors[rotorCount]->init();
        rotorCount++;
    } else {
        std::cout << "Max rotors reached!" << std::endl;
    }
}

void Enigma::changeRotor(Rotor &rotor, int posIdx) {
    m_rotors[posIdx] = &rotor;
}

void Enigma::setDailyKey(char *key) {
    m_dailyKey = key;
}

void Enigma::setMessageKey(std::string key) {
    for (int i = 0; i < m_numRotors; ++i) {
        int turns = toInt(key[i]);
        m_rotors[i]->turn(turns);
    }
}

void Enigma::reset() {
    for (int i = 0; i < m_numRotors; ++i) {
        m_rotors[i]->init();
    }
}

std::string Enigma::encrypt(const std::string &msg) {
    reset();
    applyDailyKey();
    std::string temp = msg;
    temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    std::string s = "";
    for (char c : temp) {
        int ind = toInt(c);
        for (int i = 0; i < m_numRotors; ++i) {
            ind = m_rotors[i]->getCode(ind);
        }

        ind = m_reflector.getCode(ind);

        for (int i = m_numRotors - 1; i >= 0; --i) {
            ind = m_rotors[i]->getIndex(ind);
        }

        s += toChar(ind);

        int j = 0;
        m_rotors[j]->turn(1);
        m_turns[j]++;
        while (m_turns[j] >= 26 && j < m_numRotors) {
            m_turns[j] -= 26;
            j++;
            m_rotors[j]->turn(1);
            m_turns[j]++;
        }
    }
    return s;
}

std::string Enigma::decrypt(const std::string &msg) {
    reset();
    applyDailyKey();

    std::string s = "";
    for (char c : msg) {
        int ind = toInt(c);

        for (int i = 0; i < m_numRotors; ++i) {
            ind = m_rotors[i]->getCode(ind);
        }

        ind = m_reflector.getIndex(ind);

        for (int i = m_numRotors - 1; i >= 0; --i) {
            ind = m_rotors[i]->getIndex(ind);
        }
        s += toChar(ind);

        int j = 0;
        m_rotors[j]->turn(1);
        m_turns[j]++;
        while (m_turns[j] >= 26 && j < m_numRotors) {
            m_turns[j] -= 26;
            j++;
            m_rotors[j]->turn(1);
            m_turns[j]++;
        }
    }
    return s;
}

void Enigma::applyDailyKey() {
    for (int i = 0; i < m_numRotors; ++i) {
        int turns = toInt(m_dailyKey[i]);
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

    std::cout << "-------------Reflector-------------" << std::endl;
    m_reflector.print();
}