#ifndef MYCOLLECTION_H
#define MYCOLLECTION_H
#include <iostream>

template <typename T>
class MyCollection {
public:
    virtual ~MyCollection() = default;

    virtual void push_back(const T& value) = 0;
    virtual void pop_back() = 0;
    virtual int  size()  const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;

    virtual const T& operator[](int index) const = 0;
    virtual T&       operator[](int index)       = 0;

    bool contains(const T& value) const {
      for (int i = 0; i < size(); i++) {
        if ((*this)[i] == value) return true;
      }
      return false;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyCollection<T>& c) {
  os << "[";
  for (int i = 0; i < c.size(); i++) {
    os << c[i];
    if (i < c.size() - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

#endif
