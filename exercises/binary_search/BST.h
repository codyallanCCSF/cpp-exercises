#ifndef BST_H
#define BST_H

// Struct for Node data
struct Node {

  // Data member (Payload)
  int data;

  // Pointer members (Hooks)
  Node* next;
  Node* prev;

  // Constructor (Init)
  Node(int val);
};

class LinkedList {
  private:

    // 
    Node* head;
    Node* tail;

  public:
    LinkedList();
    ~LinkedList();

    void addBack(int val);
    void display();
    void helloWorld();
};

#endif
