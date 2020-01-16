#include <iostream>
#include "headers/Calendar.h"

using namespace std;

int main() {
    Calendar c;
    Date d(20, 1, 2020);
    Date d1(22, 1, 2020);
    Date d2(28, 1, 2020);
    Date d3(29, 1, 2020);

    d1++;

    c.addEntry(d, "CG Klausur");
    c.addEntry(d3, "Audio Klausur");
    c.addEntry(d1, "WM Klausur");
    c.addEntry(d2, "AST Klausur");

    cout << (c.containsEntry("DB Klausur") ? "true" : "false") << endl;

    c.print();

    return 0;
}
