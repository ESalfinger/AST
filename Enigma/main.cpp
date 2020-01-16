#include <iostream>
#include "headers/Enigma.h"

int main() {
    Enigma enigma(3);
    enigma.addRotor(ROTOR_TYPE_I);
    enigma.addRotor(ROTOR_TYPE_II);
    enigma.addRotor(ROTOR_TYPE_III);
    enigma.addRotor(ROTOR_TYPE_IV);

    //enigma.printConfig();
    enigma.setDailyKey("abc");
    std::string msg = "Hello world";
    std::string s = enigma.encrypt(msg);
    std::cout << "Message: " << msg << std::endl;
    std::cout << "Encrypted: " << s << std::endl;
    std::cout << "Decrypted: " << enigma.decrypt(s) << std::endl;

    return 0;
}