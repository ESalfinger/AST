#ifndef ENIGMA_ENIGMA_H
#define ENIGMA_ENIGMA_H

#include "Rotor.h"
#include "Reflector.h"
#include <string>

enum RotorType {
    ROTOR_TYPE_I = 56789,
    ROTOR_TYPE_II = 33170,
    ROTOR_TYPE_III = 7013023,
    ROTOR_TYPE_IV = 3017,
    ROTOR_TYPE_V = 42,
};

const int ReflectorSeed = 37537;

class Enigma {
public :
    static int rotorCount;

    Enigma(int numRotors);

    virtual ~Enigma();

// add a rotor of a specific type
    void addRotor(RotorType type);

// exchange the rotor at position ’posIdx’
    void changeRotor(Rotor &rotor, int posIdx);

// set the daily key settings
    void setDailyKey(char *key);

// set the message key settings
    void setMessageKey(std::string key);

// clear daily and message key settings
    void reset();

// encrypt the message key with the daily key settings
// encrypt ’msg’ with the current daily and message key settings
    std::string encrypt(const std::string &msg);

// decrypt the message with current daily and message key settings
// (the message key is read at the beginning of the message)
    std::string decrypt(const std::string &msg);

// apply the message key setting (set offset for each rotor)
    void applyDailyKey();

// get the index of the char ’c’ (range: [A..Z,a..z])
    int toInt(char c);

// get the corresponding char for the int ’i’ (range: [0..NUM_LETTERS[)
    char toChar(int i);

    void printConfig();

private :
    int m_numRotors; // the number of rotors
    Rotor **m_rotors;
    Reflector m_reflector; // the reflector module
    char *m_dailyKey;// the current daily Key
    int m_turns[];
};

#endif //ENIGMA_ENIGMA_H
