#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "MyCollection.h"
#include <iostream>

template <typename T>
class MyVector : public MyCollection<T> {
public: 
    MyVector();                          
    MyVector(const MyVector& other);     
    ~MyVector();                         

    MyVector& operator=(const MyVector& other);  
    bool      operator==(const MyVector& other) const; 
    
    // Implementation of MyCollection virtual functions
    T&         operator[](int index) override;            
    const T&   operator[](int index) const override;      
    
    void push_back(const T& value) override;
    void pop_back() override;
    int  size() const override;
    bool empty() const override;
    void clear() override;

    int  capacity() const;

private:
    T* data;
    int  v_size;     // renamed to avoid conflict with size()
    int  v_capacity; 
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const MyVector<T> &v);

#endif
