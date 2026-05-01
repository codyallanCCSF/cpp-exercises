#include "BST.h"
#include <iostream>


// Constructors

Node::Node(int val) {
  data = val;
  next = nullptr;
  prev = nullptr;
}

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

// Add a new node
void LinkedList::addBack(int val) {
  Node* newNode = new Node(val);

  if (head == nullptr) {
    //For empty list, head is also tail
    head = newNode;
    tail = newNode;
  } else {
    // Update old tail's next to new node
    tail->next = newNode;
    // Assign new node's prev to current tail
    newNode->prev = tail;
    // Update tail to new node
    tail = newNode;
  }
}

void LinkedList::display() {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " <-> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

LinkedList::~LinkedList() {

  
}

void LinkedList::helloWorld() {
  std::cout << "Hello from the BST.cpp file! Link successful." << std::endl;
}

