# MyCollection Framework

A C++ template library featuring custom implementations of dynamic arrays and doubly linked lists.

## Overview
This project establishes a unified interface for data containers through the `MyCollection` abstract base class. It demonstrates the power of **Object-Oriented Programming** and **Templates** by allowing the same logic to handle integers, strings, or custom objects.

## Core Components
- **`MyCollection<T>`**: The foundation. Defines the essential behavior (push, pop, size, clear) that any container in this library must follow.
- **`MyVector<T>`**: A high-performance dynamic array. Best used when you need fast, index-based access to your data.
- **`MyLinkedList<T>`**: A memory-efficient doubly linked list. Best used for frequent additions or removals from the front or back.

## Key Technical Features
- **Manual Memory Management**: Uses `new[]` and `delete[]` for the Vector and individual node allocation for the List.
- **Deep Copy Semantics**: Custom copy constructors and assignment operators ensure that copying a container duplicates the data rather than just the pointer.
- **Operator Overloading**: Includes implementations for `[]`, `==`, and `<<` to make the containers feel like native C++ types.

