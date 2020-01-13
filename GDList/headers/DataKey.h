#ifndef DLIST_DATAKEY_H
#define DLIST_DATAKEY_H

template <typename T> class DataKey {
private:
    T m_data;

public:
    DataKey(T data) : m_data(data) {}

    bool matches(T data) {
        return m_data == data;
    }
};

#endif //DLIST_DATAKEY_H
