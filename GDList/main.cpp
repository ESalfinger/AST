#include <string>
#include <iostream>
#include "headers/GDList.h"

using namespace std;

int main() {
    GDList<string> list;

    std::string s = "World";
    std::string s1 = "Hello";
    std::string s2 = "my";
    std::string s3 = "great";

    list.append(s2);
    list.prepend(s1);
    list.prepend(s1);
    list.append(s);
    list.append(s);
    list.insertAfter(s2, s3);
    cout << list.toString() << endl;
    cout << "---------NO DOUBLES---------" << endl;
    list.removeDoubles();
    cout << list.toString() << endl;
    cout << "---------REVERSED---------" << endl;
    list.reverse();
    cout << list.toString() << endl;

    return 0;
}