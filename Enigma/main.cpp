#include <iostream>
#include "headers/Enigma.h"

int main() {
    Enigma *enigma = new Enigma(5);
    enigma->addRotor(ROTOR_TYPE_I);
    enigma->addRotor(ROTOR_TYPE_II);
    enigma->addRotor(ROTOR_TYPE_III);
    enigma->addRotor(ROTOR_TYPE_IV);
    enigma->addRotor(ROTOR_TYPE_V);

    enigma->printConfig();
    enigma->setDailyKey("axbzd");
    enigma->printConfig();
    enigma->setMessageKey("boacw");
    std::cout << enigma->encrypt("boacw") << std::endl;
    enigma->applyMsgKey();
    std::cout << enigma->encrypt("this is a test message") << std::endl;

    return 0;
}