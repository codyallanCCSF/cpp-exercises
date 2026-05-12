```markdown
# MyCollection: Templatized Data Structures

A C++ project implementing custom, templatized versions of common data structures (Vector and Doubly Linked List) under a unified abstract base interface[cite: 44]. This project was developed as a series of progressive assignments focusing on dynamic memory management, operator overloading, and object-oriented design patterns[cite: 30, 39, 47].

## Features

- **Unified Interface**: Both containers inherit from `MyCollection<T>`, providing a consistent API for common operations[cite: 44, 50].
- **`MyVector<T>`**: A dynamic array implementation with automatic resizing and deep-copy semantics[cite: 28, 35].
- **`MyLinkedList<T>`**: A doubly linked list implementation optimized for efficient insertions and removals[cite: 36, 37].
- **Generic Programming**: Fully templatized to support any data type that implements required operators[cite: 45, 51].
- **Memory Safety**: Custom destructors, copy constructors, and assignment operators to manage heap memory and prevent leaks[cite: 31, 36, 43].

## Project Structure

- `MyCollection.h`: The abstract base class defining the standard interface[cite: 48].
- `MyVector.h`: Dynamic array implementation[cite: 27].
- `MyLinkedList.h`: Doubly linked list implementation[cite: 36].
- `main.cpp`: Test suite demonstrating functionality, inheritance, and edge cases.

## API Reference

Both `MyVector` and `MyLinkedList` implement the following methods from `MyCollection`[cite: 43, 49]:

| Method | Description |
| :--- | :--- |
| `push_back(const T& value)` | Adds an element to the end. |
| `pop_back()` | Removes the last element. |
| `size()` | Returns the number of elements. |
| `empty()` | Returns true if the collection is empty. |
| `clear()` | Removes all elements and frees memory. |
| `operator[]` | Provides index-based access (O(1) for Vector, O(n) for List). |
| `contains(const T& value)` | Searches for a value within the collection[cite: 49]. |

### Additional Specialized Methods

- **MyLinkedList**: `push_front()`, `pop_front()`, and `remove(value)`.
- **MyVector**: `capacity()` to check current allocated space[cite: 31].

## Getting Started

### Prerequisites
- A C++ compiler supporting C++11 or later (e.g., `g++` or `clang++`).

### Compilation
Compile the project using the following command:
```bash
g++ -std=c++11 main.cpp -o my_collection_test
