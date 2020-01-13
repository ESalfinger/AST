#ifndef DLIST_GDLIST_H
#define DLIST_GDLIST_H

#include <sstream>
#include "Node.h"
#include "DataKey.h"

template <typename T> class GDList {
public:
    class GDListIterator {
    public:
        GDListIterator(Node<T> *start) : current(start) {}

        ~GDListIterator() {
            delete current;
        }

        bool hasNext() {
            return current != nullptr;
        }

        T next() {
            T data = current->data;
            current = current->next;
            return data;
        }

        Node<T> *current;
    };

    GDList() {};

    ~GDList() {
        delete head;
        delete tail;
    }

    void prepend(T data) {
        head = new Node<T>(nullptr, data, head);
        if (tail == nullptr) {
            tail = head;
        } else {
            head->next->prev = head;
        }
    }

    void append(T data) {
        Node<T>* new_node = new Node<T>(nullptr, data, nullptr);
        if (head == nullptr) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    bool insertAfter(T prev, T data) {
        DataKey<T> key(prev);
        Node<T> *found = forwardSearch(head, key);

        if (found != nullptr) {
            insertAfter(found, data);
            return true;
        }

        return false;
    }

    T forwardSearch(DataKey<T> &key) {
        Node<T> *foundNode = forwardSearch(head, key);

        return foundNode != nullptr ? foundNode->data : NULL;
    }

    void forwardRemove(T data) {
        DataKey<T> key(data);
        Node<T> *toRemove = forwardSearch(head, key);

        removeNode(toRemove);
    }

    void removeDoubles() {
        Node<T> *current = head;

        while (current != nullptr) {
            DataKey<T> key(current->getData());
            Node<T> *toRemove = forwardSearch(current->next, key);
            removeNode(toRemove);

            current = current->next;
        }
    }

    void reverse() {
        Node<T> *current = head;

        while (current != nullptr) {
            Node<T> *dummy = current->prev;
            current->prev = current->next;
            current->next = dummy;
            current = current->prev;
        }

        Node<T> *dummy = head;
        head = tail;
        tail = dummy;
    }

    GDListIterator begin() {
        return GDListIterator(head);
    }

    GDListIterator end() {
        return GDListIterator(tail);
    }

    std::string toString() {
        GDListIterator it = begin();
        std::stringstream ss;

        while (it.hasNext()) {
            ss << it.next() << std::endl;
        }

        return ss.str();
    }

protected:
    Node<T> *tail = nullptr;
    Node<T> *head = nullptr;

    void insertAfter(Node<T> *current, T data) {
        Node<T> *dummy = current->next;
        current->next = new Node<T>(current, data, dummy);
        dummy->prev = current->next;
    }

    Node<T> *forwardSearch(Node<T> *current, DataKey<T> &key) {

        while (current != nullptr && !key.matches(current->getData())) {
            current = current->next;
        }

        return current;
    }

private:
    void removeNode(Node<T> *toRemove) {
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
};

#endif //DLIST_GDLIST_H
