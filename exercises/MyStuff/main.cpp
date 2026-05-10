#include "MyVector.h"
#include <string>
#include <iostream>
#include <cassert>

int main() {

  // 1. Test basic functionality and templates
  std::cout << "--- Testing Basic Functionality ---\n";

  MyVector<int> v1;
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);

  std::cout << "v1 (initial): " << v1 << " | Size: "
    << v1.size() << "\n";

  // 2. Test Capacity Growth
  std::cout << "Current capacity: " << v1.capacity() << "\n";

  // 3. Test Deep Copy (Copy Constructor)
  std::cout << "\n--- Testing Deep Copy Constructor ---\n";

  MyVector<int> v2 = v1;
  v2.push_back(40);

  std::cout << "v1 (original): " << v1 << "\n";
  std::cout << "v2 (copied + 40): " << v2 << "\n";

  //Check if modifying v2 affected v1
  if (v1.size() != v2.size()) {
    std::cout << "SUCCESS: v1 and v2 are independent (Deep Copy).\n";
  }

  // Test Equality Operator (operator==)
  std::cout << "\n--- Testing Equality ---\n";

  MyVector<int> v3;
  v3.push_back(10);
  v3.push_back(20);
  v3.push_back(30);

  std::cout << "v1 == v3? " 
    << (v1 == v3 ? "True" : "False") << "\n";

  v3.push_back(99);

  std::cout << "v1 == v3 (after adding 99)? "
    << (v1 == v3 ? "True" : "False") << "\n";

  // Test Assignment Operator
  std::cout << "\n--- Testing Assignment & Self-Assignment ---\n";

  MyVector<int> v4;
  v4 = v1;
  std::cout << "v4 after assignment: " << v4 << "\n";

  // Testing Self-Assignment
  v4 = v4;
  std::cout << "v4 after self-assignment: " 
    << v4 << " (should be same)\n";

  // 6. Test Mutator Subscript (operator[])
  std::cout << "\n--- Testing Subscript Mutator ---\n";
  
  v1[0] = 100;

  std::cout << "v1 after reassigning v1[0]: " << v1 << "\n";

  // 7. Testing with strings
  std::cout << "\n--- Testing with Strings ---\n";

  MyVector<std::string> words;

  words.push_back("Hello");
  words.push_back("World!");
  
  std::cout << "Word Vector: " << words << "\n";
  std::cout << "Contains 'World! " 
    << (words.contains("World!") ? "Yes" : "No") << "\n";

  // Test Deep Copy with Strings
  MyVector<std::string> backup;
  backup = words;
  words[0] = "Goodbye";

  std::cout << "Original after change: " << words[0] << "\n";
  std::cout << "Backup (should be Hello): " << backup[0] << "\n";

  return 0;
}
