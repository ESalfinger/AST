//
// Created by Elias Salfinger on 28.11.19.
//
#include "headers/Enigma.h"

Enigma::Enigma(int numRotors) : m_numRotors(numRotors), m_reflector(Reflector(12)){
    m_rotors = new Rotor *[m_numRotors];
}

Enigma::~Enigma() {

}

void Enigma::addRotor(RotorType type) {

}

void Enigma::changeRotor(Rotor &rotor, int posIdx) {

}

void Enigma::setDailyKey(char *key) {

}

void Enigma::setMessageKey(char *key) {

}

void Enigma::reset() {

}

std::string Enigma::encrypt(const std::string &msg) {
    return std::string();
}

std::string Enigma::decrypt(const std::string &msg) {
    return std::string();
}

void Enigma::applyMsgKey() {

}

int Enigma::toInt(char c) {
    return 0;
}

char Enigma::toChar(int i) {
    return 0;
}
