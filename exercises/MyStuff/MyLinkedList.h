#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "MyCollection.h"
#include <iostream>

template <typename T>
struct Node {
    T     value;
    Node *prev;
    Node *next;
};

template <typename T>
class MyLinkedList : public MyCollection<T> {
public:
    MyLinkedList();
    MyLinkedList(const MyLinkedList& other);
    ~MyLinkedList();

    MyLinkedList& operator=(const MyLinkedList& other);
    bool          operator==(const MyLinkedList& other) const;

    // Implementation of MyCollection virtual functions
    void push_back(const T& value) override;
    void pop_back() override;
    int  size() const override;
    bool empty() const override;
    void clear() override;
    
    // Note: operator[] must be implemented for MyCollection compliance
    T&       operator[](int index) override;
    const T& operator[](int index) const override;

    void push_front(const T& value);
    void pop_front();
    bool remove(const T& value);   

private:
    Node<T> *head;
    int      l_size; // helpful for O(1) size() calls
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyLinkedList<T>& list);

#endif
