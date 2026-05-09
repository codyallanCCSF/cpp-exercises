#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "MyCollection.h"
#include <iostream>

template <typename T>
class MyVector : public MyCollection<T> {
  public:

    // Constructors

    MyVector() {
      v_size = 0;
      v_capacity = 2;
      data = new T[v_capacity];
    }

    MyVector(const MyVector& other) {
      v_size = other.v_size;
      v_capacity = other.v_capacity;
      data = new T[v_capacity];

      for (int i = 0; i < v_size; i++) {
        data[i] = other.data[i];
      }
    }     

    // Destructor

    ~MyVector() {
      delete[] data;
    }                         

    // Operator Overloading

    MyVector& operator=(const MyVector& other) {
      if (this != &other) {
        delete[] data;
        v_size = other.v_size;
        v_capacity = other.v_capacity;
        data = new T[v_capacity];
        for (int i = 0; i < v_size; i++) {
          data[i] = other.data[i];
        }
      }
      return *this;
    }

      
    bool operator==(const MyVector& other) const {
      if (v_size != other.v_size) return false;
      for (int i = 0; i < v_size; i++) {
        if (data[i] = other.data[i]) return false;
      }
      return true;
    } 

    T& operator[](int index) override {
      return data[index];
    }
      
    const T& operator[](int index) const override {
      return data[index];
    }      


    // Pure Virtual Function Implementation

    void push_back(const T& value) override {
      if (v_size == v_capacity) {
        v_capacity *= 2;
        T* newData = new T[v_capacity];
        for (int i = 0; i < v_size; i++) {
          newData[i] = data[i];
        }
        delete[] data;
        data = newData;
      }
      data[v_size++] = value;
    }
    void pop_back() override {
      if (v_size > 0) v_size--;
    }

    int  size() const override {
      return v_size;
    }

    bool empty() const override {
      return v_size == 0;
    }

    void clear() override {
      v_size = 0;
    }

    int  capacity() const;

  private:
    T* data;
    int  v_size;     // renamed to avoid conflict with size()
    int  v_capacity; 
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const MyVector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i < v.size() - 1) os << ", ";
  }
  os << "]";
  return os;
}

#endif
