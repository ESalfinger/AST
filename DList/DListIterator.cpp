//
// Created by Elias Salfinger on 20.11.19.
//

#include "headers/DListIterator.h"

DListIterator::DListIterator(Node *start) : current(start) {}

DListIterator::~DListIterator() {
    delete current;
}

bool DListIterator::hasNext() {
    return current != nullptr;
}

void *DListIterator::next() {
    void *data = current->data;
    current = current->next;
    return data;
}
