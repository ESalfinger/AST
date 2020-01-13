#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include "EncoderModule.h"

class Reflector : public EncoderModule {
public :
    // call super constructor in initializer list
    Reflector(int randSeed) : EncoderModule(randSeed) {}

    virtual ~Reflector();

    virtual void init();
};

#endif //ENIGMA_REFLECTOR_H
