#include "MyLinkedList.h"
#include <string>
#include <iostream>
#include <cassert>

int main() {
    // 1. Test Basic Functionality & Inheritance
    std::cout << "--- Testing Basic Functionality (push_back/size/empty) ---\n";
    MyLinkedList<int> list;
    
    std::cout << "Is empty? " << (list.empty() ? "Yes" : "No") << "\n";
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    std::cout << "List: " << list << " | Size: " << list.size() << "\n";

    // 2. Test Linked List Specifics (Front operations)
    std::cout << "\n--- Testing push_front & pop_front ---\n";
    list.push_front(5);
    std::cout << "After push_front(5): " << list << "\n";
    
    list.pop_front();
    std::cout << "After pop_front: " << list << " (should be back to [10, 20, 30])\n";

    // 3. Test the remove(value) function
    std::cout << "\n--- Testing remove(value) ---\n";
    list.push_back(40);
    std::cout << "Before remove: " << list << "\n";
    
    bool removed = list.remove(20);
    std::cout << "Removed 20? " << (removed ? "Yes" : "No") << "\n";
    std::cout << "After removing 20: " << list << "\n";
    
    list.remove(10); // Remove head
    list.remove(40); // Remove tail
    std::cout << "After removing head (10) and tail (40): " << list << "\n";

    // 4. Test Deep Copy (Copy Constructor)
    std::cout << "\n--- Testing Copy Constructor (Deep Copy) ---\n";
    MyLinkedList<int> list2 = list;
    list2.push_back(99);
    
    std::cout << "Original: " << list << "\n";
    std::cout << "Copy + 99: " << list2 << "\n";
    if (list.size() != list2.size()) {
        std::cout << "SUCCESS: Independent memory detected.\n";
    }

    // 5. Test Assignment Operator & Self-Assignment
    std::cout << "\n--- Testing Assignment Operator ---\n";
    MyLinkedList<int> list3;
    list3 = list2;
    std::cout << "List3 after assignment: " << list3 << "\n";
    
    list3 = list3; // Self-assignment check
    std::cout << "List3 after self-assignment: " << list3 << "\n";

    // 6. Test Equality Operator
    std::cout << "\n--- Testing Equality ---\n";
    MyLinkedList<int> list4;
    list4.push_back(30);
    list4.push_back(99);
    
    std::cout << "List2 == List4? " << (list2 == list4 ? "True" : "False") << "\n";
    list4.push_back(100);
    std::cout << "List2 == List4 (after adding 100)? " << (list2 == list4 ? "True" : "False") << "\n";

    // 7. Test with Strings (Template check)
    std::cout << "\n--- Testing with Strings ---\n";
    MyLinkedList<std::string> names;
    names.push_back("Alice");
    names.push_back("Bob");
    
    std::cout << "Names: " << names << "\n";
    std::cout << "Contains 'Alice'? " << (names.contains("Alice") ? "Yes" : "No") << "\n";

    // 8. Test Clear
    std::cout << "\n--- Testing Clear ---\n";
    list.clear();
    std::cout << "List size after clear: " << list.size() << "\n";
    std::cout << "Is empty? " << (list.empty() ? "Yes" : "No") << "\n";

    return 0;
}
