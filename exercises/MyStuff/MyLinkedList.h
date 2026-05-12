#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "MyCollection.h"
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T value;
    Node *prev;
    Node *next;

    Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class MyLinkedList : public MyCollection<T> {


private:
    Node<T> *head;
    Node<T> *tail;
    int l_size; // helpful for O(1) size() calls


public:
    MyLinkedList() : head(nullptr), tail(nullptr), l_size(0) {}

    MyLinkedList(const MyLinkedList& other) :
      head(nullptr), tail(nullptr), l_size(0) {
        Node<T>* current = other.head;
        while (current != nullptr) {
          push_back(current->value);
          current = current->next;
        }
      }

    ~MyLinkedList() {
      clear();
    }

    MyLinkedList& operator=(const MyLinkedList& other) {
      if (this != &other) {
        clear();
        Node<T>* current = other.head;
        while (current != nullptr) {
          push_back(current->value);
          current = current->next;
        }
      }
      return *this;
    }


    bool operator==(const MyLinkedList& other) const {
      if (l_size != other.l_size) return false;
      Node<T>* left = head;
      Node<T>* right = other.head;
      while (left != nullptr) {
        if (left->value != right->value) return false;
        left = left->next;
        right = right->next;
      }
      return true;
    }

    // Implementation of MyCollection virtual functions
    void push_back(const T& value) override {
      Node<T>* newNode = new Node<T>(value);
      if (empty()) {
        head = tail = newNode;
      } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
      l_size++;
    }


    void pop_back() override {
      if (empty()) return;
      Node<T>* temp = tail;
      if (head == tail) {
        head = tail = nullptr;
      } else {
        tail = tail->prev;
        tail->next = nullptr;
      }
      delete temp;
      l_size--;
    }


    int  size() const override {
      return l_size;
    }


    bool empty() const override {
      return head == nullptr;
    }


    void clear() override {
      while (!empty()) {
        pop_back();
      }
    }

    
    // Note: operator[] must be implemented for MyCollection compliance
    
    T& operator[](int index) override {
      Node<T>* current = head;
      for (int i = 0; i < index; i++) {
        current = current->next;
      }
      return current->value;
    }


    const T& operator[](int index) const override {
      Node<T>* current = head;
      for (int i = 0; i < index; i++) {
        current = current->next;
      }
      return current->value;
    }


    void push_front(const T& value) {   
      Node<T>* newNode = new Node<T>(value);
      if (empty()) {
        head = tail = newNode;
      } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
      l_size++;
    }


    void pop_front() {
      if (empty()) return;
      Node<T>* temp = head;
      if (head == tail) {
        head = tail = nullptr;
      } else {
        head = head->next;
        head->prev = nullptr;
      }
      delete temp;
      l_size--;
    }

    bool remove(const T& value) {
          Node<T>* current = head;

          while (current != nullptr) {

            if (current->value == value) {

              if (current->prev != nullptr) {
                current->prev->next = current->next;
              } else {
                head = current->next;
              } 

              if (current->next != nullptr) {
                current->next->prev = current->prev;
              } else {
                tail = current->prev;
              }

              delete current;
              l_size--;
              return true;
            }
            current = current->next;
          }
          return false;
        }   

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyLinkedList<T>& list) {
  os << "[";
  for (int i = 0; i < list.size(); i++) {
    os << list[i];
    if (i < list.size() - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}


#endif
