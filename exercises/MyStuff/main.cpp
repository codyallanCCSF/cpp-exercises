#include "MyCollection.h"
#include "MyVector.h"
#include <iostream>

int main() {
  MyVector<int> nums;
  nums.push_back(42);

  MyVector<std::string> names;
  names.push_back("Cody");

  std::cout << "Int size: " << nums.size() 
    << " | String size: " << names.size()
    << std::endl;
  
  return 0;
}
