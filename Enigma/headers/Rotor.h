#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include "EncoderModule.h"

class Rotor : public EncoderModule {
public :
// call super constructor in initializer list
    Rotor(int randSeed) : EncoderModule(randSeed) {}

    virtual ~Rotor();

    virtual void init();

    void turn(int times);
};

#endif //ENIGMA_ROTOR_H
