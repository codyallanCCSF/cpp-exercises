#include "BST.h"
#include <iostream>


// LinkedList Constructors - Node, LinkedList

Node::Node(int val) {
  data = val;
  next = nullptr;
  prev = nullptr;
}

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

// Destructor

LinkedList::~LinkedList() {

  Node* current = head;
  
  while (current != nullptr) {
    Node* nextNode = current->next;
    std::cout << "Deleting node at " << current << std::endl;
    delete current;
    current = nextNode;
  }

  head = nullptr;
  tail = nullptr;
}

// LinkedList Methods - addback(), display(), getFirst()

void LinkedList::addBack(int val) {
// Adds a new node to the end of the list

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
// Prints data at each node in list, head->tail

  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " <-> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

int LinkedList::getFirst() {
// Returns the data stored in the first node

  if (head == nullptr) {
    return -1;
  }
  return head->data;
}

void LinkedList::helloWorld() {
  std::cout << "Hello from the BST.cpp file! Link successful."
    << std::endl;
}

