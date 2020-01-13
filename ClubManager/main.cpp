#include <iostream>
#include "headers/TopAthlete.h"
#include "headers/AmateurAthlete.h"
#include "headers/ChairMember.h"
#include "headers/Trainer.h"
#include "headers/HonoraryMember.h"
#include "headers/SupportingMember.h"
#include "headers/Society.h"

int main() {
    AmateurAthlete m01("Sophie", 2);
    TopAthlete m02("Lukas", 5);
    Trainer m03("Paul", 8);

    ChairMember m04("Thomas", 7);
    HonoraryMember m05("Christoph");
    SupportingMember m06("Claudia");

    Trainer m07("Anna", 4);

    Society s("Club 1", 6);
    Society s1("Club 2", 2);

    s.addMember(&m01);
    s.addMember(&m02);
    s.addMember(&m03);
    s.addMember(&m04);
    s.addMember(&m05);

    s.addMember(&s1);
    s.addMember(&m06);

    s1.addMember(&m02);
    s1.addMember(&m07);
    s1.addMember(&m03);

    cout << s.toString() << endl;

    s.removeMember(m01.getMNumber());
    //s.removeMember(s1.getMNumber());

    cout << s.toString() << endl;

    return 0;
}
