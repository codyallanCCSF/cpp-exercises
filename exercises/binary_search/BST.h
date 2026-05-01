#ifndef BST_H
#define BST_H

// Struct for Node data
struct Node {
  int data;
  Node* next;
  Node* prev;

  Node(int val);
};

class LinkedList {
  private:
    Node* head;
    Node* tail;

  public:
    LinkedList();
    ~LinkedList();
}

#endif
