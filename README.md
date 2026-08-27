# Singly Linked List Data Structure (C++) 🔗

A custom C++ implementation of a Singly Linked List designed for dynamic catalog item management, node traversal, and memory cleanup.

## 🚀 Key Features

* **Dynamic Node Operations:**
  * `addToStart` / `addToEnd`: Constant-time prepending and iterative appending.
  * `deleteElement`: Target deletion by string key with proper pointer re-linking.
  * `find`: Linear search by item identifier/name.
* **Memory Management:** Full sequential memory deallocation (`delList`) using raw pointers (`delete`).
* **Operator Overloading:** Custom stream insertion (`operator<<`) for easy console formatting of node records.

## 🧱 Data Model

Each node holds structured item metadata:
```cpp
struct Tovar {
    char name[100];
    char owner[100];
    int year;
    float price;
    Tovar* next;
};
