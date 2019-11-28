#include <string>
#include <iostream>

#include "headers/DList.h"

int main() {
    DList *list = new DList();

    std::string s = "World";
    std::string s1 = "Hello";
    std::string s2 = "my";
    std::string s3 = "great";

    list->append(&s2);
    list->prepend(&s1);
    list->prepend(&s1);
    list->append(&s);
    list->append(&s);
    list->insertAfter(&s2, &s3);
    list->printList();
    std::cout << "---------NO DOUBLES---------" << std::endl;
    list->removeDoubles();
    list->printList();
    std::cout << "---------REVERSED---------" << std::endl;
    list->reverse();
    list->printList();

    return 0;
}