#include <iostream>
#include "headers/Enigma.h"

int main() {
    Enigma enigma(3);
    enigma.addRotor(ROTOR_TYPE_I);
    enigma.addRotor(ROTOR_TYPE_II);
    enigma.addRotor(ROTOR_TYPE_III);
    enigma.addRotor(ROTOR_TYPE_IV);
    enigma.addRotor(ROTOR_TYPE_V);

    //enigma.printConfig();
    enigma.setDailyKey("abc");
    std::string s = enigma.encrypt("Hello world");
    std::cout << enigma.decrypt(s) << std::endl;

    return 0;
}