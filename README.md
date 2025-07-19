# SinglyLinkedList-CPP

A modern C++ wrapper class for a Singly Linked List with full support for insertion, removal, deep copy, move semantics, and memory-safe destruction.
A modern, object-oriented C++ implementation of a singly linked list. This project supports basic and advanced operations such as:

- Insert at head
- Insert at tail
- Insert at specific position
- Remove from specific index
- Clear the list
- Copy constructor (deep copy)
- Move constructor (ownership transfer)

---

## 🚀 Features

- ✅ Clean, modular design
- ✅ Safe memory management (no leaks)
- ✅ Supports Rule of Five (copy/move constructor and assignment)
- ✅ Easy to integrate and test

---

## 🧱 Class Structure

```cpp
class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    SinglyLinkedList();                         // Default constructor
    SinglyLinkedList(const SinglyLinkedList&);  // Copy constructor
    SinglyLinkedList(SinglyLinkedList&&);       // Move constructor
    ~SinglyLinkedList();                        // Destructor

    void insertAtHead(int value);
    void insertAtTail(int value);
    void insertAt(int index, int value);
    void removeAt(int index);
    void clear();
    void print() const;
};

