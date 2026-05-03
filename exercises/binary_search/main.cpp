#include "BST.h"
#include <iostream>

int main() {
  LinkedList myList;

  myList.helloWorld();

  myList.addBack(10);
  myList.addBack(20);

  std::cout << "The first value is: " 
    << myList.getFirst() << std::endl;

  myList.display();

  return 0;
}
