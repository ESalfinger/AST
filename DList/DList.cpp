#include "headers/DList.h"
#include "headers/PointerKey.h"
#include "headers/DListIterator.h"
#include <iostream>

DList::DList() {}

DList::~DList() {
    delete head;
    delete tail;
}

void DList::prepend(void *data) {
    head = new Node(nullptr, data, head);
    if (tail == nullptr) {
        tail = head;
    } else {
        head->next->prev = head;
    }
}

void DList::append(void *data) {
    tail = new Node(tail, data, nullptr);
    head == nullptr ? head = tail : tail->prev->next = tail;
}

bool DList::insertAfter(void *prev, void *data) {
    PointerKey key(prev);
    Node *found = forwardSearch(head, key);

    if (found != nullptr) {
        insertAfter(found, data);
        return true;
    }

    return false;
}

void DList::insertAfter(Node *current, void *data) {
    Node *dummy = current->next;
    current->next = new Node(current, data, dummy);
    dummy->prev = current->next;
}

Node *DList::forwardSearch(Node *current, IKey &key) {
    while (current != nullptr && !key.matches(current->getData())) {
        current = current->next;
    }

    return current;
}

void *DList::forwardSearch(IKey &key) {
    Node *foundNode = forwardSearch(head, key);

    return foundNode != nullptr ? foundNode->data : nullptr;
}

void DList::forwardRemove(void *data) {
    PointerKey key(data);
    Node *toRemove = forwardSearch(head, key);

    removeNode(toRemove);
}

void DList::removeDoubles() {
    Node *current = head;

    while (current != nullptr) {
        PointerKey key(current->getData());
        Node *toRemove = forwardSearch(current->next, key);
        removeNode(toRemove);

        current = current->next;
    }
}

void DList::reverse() {
    Node *current = head;

    while (current != nullptr) {
        Node *dummy = current->prev;
        current->prev = current->next;
        current->next = dummy;
        current = current->prev;
    }

    Node *dummy = head;
    head = tail;
    tail = dummy;
}

IFIterator *DList::iterator() {
    return new DListIterator(head);
}

void DList::removeNode(Node *toRemove) {
    if (toRemove != nullptr) {
        if (toRemove == head) {
            head = toRemove->next;
        } else {
            toRemove->prev->next = toRemove->next;
        }
        if (toRemove == tail) {
            tail = toRemove->prev;
        } else {
            toRemove->next->prev = toRemove->prev;
        }

        delete toRemove;
    }
}

void DList::printList(){
    IFIterator *it = iterator();

    while (it->hasNext()) {
        std::cout << *(std::string*)it->next() << std::endl;
    }
}
