#include <cstdlib>
#include "headers/Reflector.h"

Reflector::~Reflector() {

}

void Reflector::init() {
    int visited[NUM_LETTERS] = {};
    int count = 0;
    while (count < NUM_LETTERS) {
        int num = rand() % NUM_LETTERS;

        // check if num has already been generated
        if (visited[num] == 0) {
            // now mark it as visited
            visited[num] = 1;
            m_configuration[count++] = num;  // store the generated number in an array.
        }
    }
}
