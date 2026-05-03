#ifndef BST_H
#define BST_H

struct Node {
// Properties of Node data type
  
  Node(int val);
  Node* next;
  Node* prev;
  int data;

};

class LinkedList {
// LinkedList manager class

  private:

    Node* head;
    Node* tail;

  public:

    LinkedList();
    ~LinkedList();

    void addBack(int val);
    void display();
    void helloWorld();

    int getFirst();
};

#endif
