#include "MyVector.h"
#include <string>
#include <iostream>

int main() {
  MyVector<int> v;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  std::cout << "Integer Vector: " << v << "\n";
  std::cout << "Contains 20? " << v.contains(20) << "\n";
  std::cout << "Contains 21? " << v.contains(21) << "\n";


  return 0;
}
