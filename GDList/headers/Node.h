#ifndef DLIST_NODE_H
#define DLIST_NODE_H

template <typename T> class Node {
public:
    Node(Node *prev, T data, Node *next) :prev(prev), data(data), next(next){}

    T getData() { return data; }
private:
    Node *prev;
    Node *next;
    T data;

    template <typename U> friend class GDList;
};

#endif //DLIST_NODE_H
